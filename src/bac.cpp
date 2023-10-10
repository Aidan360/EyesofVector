#include "bac.hpp" 
#include "main.h"
#include "pros/motors.hpp"
#include "math.h"
void BasicChassis::goForward(double distance, double velocity) {
    double rotationDegrees = ((distance/wheelSize * 360)/2*-1);
    double lastDegrees = ((distance/wheelSize * 360)/2*-1)* 0.05;
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_relative(motorPortLeft[i],rotationDegrees,velocity*velVol);
        pros::c::motor_move_relative(motorPortRight[i],rotationDegrees,velocity*velVol);
    }
    while (!((pros::c::motor_get_position(motorPortLeft[0])<  rotationDegrees + 5) && (pros::c::motor_get_position(motorPortLeft[0]) > rotationDegrees - 5))) {
    pros::delay(1);
    }

}

void BasicChassis::turn(double degrees, double velocity) {
    double distance = (degrees * M_PI/180) * (trackLength/2);
    double rotationDegrees = (distance/wheelSize * 360)/2 * 0.95;  
    double lastDegrees = (distance/wheelSize * 360)/2 * 0.05; 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_absolute(motorPortLeft[i],-rotationDegrees,(-1*velocity*velVol));
        pros::c::motor_move_absolute(motorPortRight[i],rotationDegrees,(velocity*velVol));
    }  
    while (!((pros::c::motor_get_position(motorPortLeft[0])<  rotationDegrees + 5) && (pros::c::motor_get_position(motorPortLeft[0]) > rotationDegrees - 5))) {
    pros::delay(1);
    }

}

