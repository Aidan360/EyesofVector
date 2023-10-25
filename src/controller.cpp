#include "display/lv_core/lv_refr.h"
#include "main.h"
#include "initialize.hpp"
#include "controller.hpp"
#include "pros/imu.h"
#include "pros/motors.h"
#include <ctime>
#include "math.h"
// ALEXIS THIS IS NOT FOR THE ACTUAL CONTROLLER, THIS IS FOR THE PID FEED FORWARD CONTROLLER
/*int sgn(double x) {
    if (x > 0) {
        return(1);
    }
    else if (x < 0) {
        return (-1);
    }
    else {
        return (0);
    }
} */
double vectorR::motorClass::getPosition() {
    return(pros::c::motor_get_raw_position(motorPort,NULL));
}
double vectorR::motorClass::getVelocity() {
    return(pros::c::motor_get_actual_velocity(motorPort));

}

int vectorR::moveController::moveTo(double input) {
    //error = inputSensor - input;
    integral = integral + error; 
    derivative = error - lastError;
   // output = kP*error + kI*integral + kD*derivative + (kS*sgn(error)); 
    return (1);
}
void vectorR::moveController::recordAccelerate(){
    acel.open(name + ".cpp");
    if (acel){}
    else 
    {
        std::ofstream acel(name + "cpp"); 
        acel << "#include <string> #include <vector> std::vector<float> poleDistances;";
    }
}


int ControllerThread() {

    while (true) {
        
        
        
        
        
        
        pros::delay(10);
    }
};