#include "launcher.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
int globalRPM;
int pidControl;
void flyWheel::spinAt(float rpm) {
    double lastError = 0;
    double error = rpm/7 - pros::c::motor_get_actual_velocity(flyWheelPort); 
    double integral = 0;
    double derivative = 0; 
    int intError = sgn(error);
    double output;
    double avgSpeed = 0; 
    int count = 0;
    double diffrence = 0;
    double lastCheck = 0;
    int count2 = 0;
    while (true) {
        pros::lcd::print(1, "Flywheel Speed: %d\n",int((pros::c::motor_get_actual_velocity(flyWheelPort)*7*3)));
        pros::lcd::print(2,"PIDFF Control : %d\n", pidControl);
        pros::lcd::print(3,"1 sec Avg : %d\n", int(avgSpeed));
        pros::lcd::print(4,"5 sec difference : %d\n", int(diffrence));
        error = rpm/7 - pros::c::motor_get_actual_velocity(flyWheelPort); 
        integral = integral + error;
        derivative = error - lastError;
        if (pidControl == 0) {
             output = -1*(kP*error + kI*integral + kD*derivative + sgn(error)*kS + kV*pros::c::motor_get_actual_velocity(flyWheelPort)); 
          }
        else if ((globalRPM = 0)) {
            output = 0;
        }
        else {
            output = -1*(kP*error + kI*integral + kD*derivative + sgn(error)*kS + kV*pros::c::motor_get_actual_velocity(flyWheelPort)); 
        }
        pros::c::motor_move_voltage(flyWheelPort, output);
        if (sgn(error) != intError) {
            integral = 0;
            intError = sgn(error);
        }
        rpm = globalRPM; 
        count = count + 1;
        count2 = count2 + 1;
        if (count >= 100) {
            avgSpeed = int((pros::c::motor_get_actual_velocity(flyWheelPort)*7*3));
            count = 0;
        }
        if (count2 >= 500) {    
            diffrence = int((pros::c::motor_get_actual_velocity(flyWheelPort)*7*3)) - lastCheck; 
            count2 = 0;
            lastCheck = int((pros::c::motor_get_actual_velocity(flyWheelPort)*7*3));
        }

        pros::delay(10);

    }

}