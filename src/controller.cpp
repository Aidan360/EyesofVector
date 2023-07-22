#include "display/lv_core/lv_refr.h"
#include "main.h"
#include "initialize.hpp"
#include "controller.hpp"
#include "pros/motors.h"
#include <ctime>
// ALEXIS THIS IS NOT FOR THE ACTUAL CONTROLLER, THIS IS FOR THE PID FEED FORWARD CONTROLLER
int sgn(double x) {
    if (x > 0) {
        return(1);
    }
    else if (x < 0) {
        return (-1);
    }
    else {
        return (0);
    }
}
double vectorR::motorClass::getPosition() {
    position = pros::c::motor_get_raw_position(motorPort,NULL);
}
double vectorR::motorClass::getVelocity() {
    velocity = pros::c::motor_get_actual_velocity(motorPort);
}

int vectorR::moveController::moveTo(double input) {
    //error = inputSensor - input;
    integral = integral + error; 
    derivative = error - lastError;
    output = kP*error + kI*integral + kD*derivative + (kS*sgn(error)); 
    return (1);
}