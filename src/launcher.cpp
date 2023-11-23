#include "launcher.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
#include "pros/motors.h"

void flyWheel::spinAt(float rpm) {
    double lastError = 0;
    double error = rpm/7 - pros::c::motor_get_actual_velocity(flyWheelPort); 
    double integral = 0;
    double derivative = 0; 
    int intError = sgn(error);

    while (kill == false) {
        pros::lcd::print(2, "Flywheel Speed%d\n",int(rpm));

        error = rpm/7 - pros::c::motor_get_actual_velocity(flyWheelPort); 
        integral = integral + error;
        derivative = error - lastError;
        double output = kP*error + kI*integral + kD*derivative + sgn(error)*kS + kV*pros::c::motor_get_actual_velocity(flyWheelPort); 
        if (sgn(error) != intError) {
            integral = 0;
            intError = sgn(error);
        }
        rpm = globalRPM; 
    }

}