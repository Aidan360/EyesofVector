#include "bac.hpp" 
#include "main.h"
#include "pros/motors.hpp"
void vectorR::BasicChassis::goForward(double distance, double velocity) {
    double rotationDegrees = distance/wheelSize * 360;
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_relative(motorPortLeft[i],rotationDegrees,velocity*velVol);
        pros::c::motor_move_relative(motorPortRight[i],rotationDegrees,-velocity*velVol);
    }
}

void vectorR::BasicChassis::turn(double degrees, double velocity) {
    double distance = (degrees * M_PI/180) * trackLength;
    double rotationDegrees = (distance/wheelSize * 360)/2;   
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_relative(motorPortLeft[i],rotationDegrees,velocity*velVol);
        pros::c::motor_move_relative(motorPortRight[i],rotationDegrees,velocity*velVol);
    }
}