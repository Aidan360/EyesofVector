#include "bac.hpp" 
#include "main.h"
#include "pros/motors.hpp"
#include "math.h"
double abso(double x) {
    if (0 > x) {
        return(x * -1);
    }
    else {
        return(x);
    }
}
 
void BasicChassis::goForward(double distance, double velocity) { // Horizontal 
    double rotationDegrees = ((distance/wheelSize * 360)/2) * -0.90;
    double lastDegrees = ((distance/wheelSize * 360)/2)* 0.05;
    
    for (int i = 0; i < std::size(motorPortLeft); ++i) { 
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }    
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_velocity(motorPortLeft[i],velocity*velVol*-0.3);
        pros::c::motor_move_velocity(motorPortRight[i],velocity*velVol*-0.3);
    }
    while (!((abso(pros::c::motor_get_position(motorPortLeft[0])) > (abso(lastDegrees) - 5)))) {
    pros::delay(1);
    } 
    
    for (int i = 0; i < std::size(motorPortLeft); ++i) { 
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_velocity(motorPortLeft[i],velocity*velVol*-1);
        pros::c::motor_move_velocity(motorPortRight[i],velocity*velVol*-1);
    } 

  
    while (!((abso(pros::c::motor_get_position(motorPortLeft[0])) > (abso(rotationDegrees) - 5)))) {
    pros::delay(1);
    } 
    for (int i = 0; i < std::size(motorPortLeft); ++i) { 
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_velocity(motorPortLeft[i],velocity*velVol*-0.5);
        pros::c::motor_move_velocity(motorPortRight[i],velocity*velVol*-0.5);
    }
    while (!((abso(pros::c::motor_get_position(motorPortLeft[0])) > (abso(lastDegrees) - 5)))) {
    pros::delay(1);
    } 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_velocity(motorPortLeft[i],0);
        pros::c::motor_move_velocity(motorPortRight[i],0);
        pros::c::motor_set_brake_mode(motorPortLeft[i],MOTOR_BRAKE_BRAKE);
        pros::c::motor_set_brake_mode(motorPortRight[i],MOTOR_BRAKE_BRAKE);
        pros::c::motor_brake(motorPortLeft[i]);
        pros::c::motor_brake(motorPortRight[i]);
    }
 

}
 /* for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_relative(motorPortLeft[i],rotationDegrees,velocity*velVol);
        pros::c::motor_move_relative(motorPortRight[i],rotationDegrees,velocity*velVol);
    } */
void BasicChassis::turn(double degrees, double velocity) {
    double distance = (degrees * M_PI/180) * (trackLength/2);
    double rotationDegrees = (distance/wheelSize * 360)/2 * 0.95;  
    double lastDegrees = (distance/wheelSize * 360)/2 * 0.05; 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }

for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_velocity(motorPortLeft[i],velocity*velVol*-0.3);
        pros::c::motor_move_velocity(motorPortRight[i],velocity*velVol*0.3);
    }
    while (!((abso(pros::c::motor_get_position(motorPortLeft[0])) > (abso(lastDegrees) - 5)))) {
    pros::delay(1);
    } 
    
    for (int i = 0; i < std::size(motorPortLeft); ++i) { 
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_velocity(motorPortLeft[i],velocity*velVol*-1);
        pros::c::motor_move_velocity(motorPortRight[i],velocity*velVol*1);
    } 

  
    while (!((abso(pros::c::motor_get_position(motorPortLeft[0])) > (abso(rotationDegrees) - 5)))) {
    pros::delay(1);
    } 
    for (int i = 0; i < std::size(motorPortLeft); ++i) { 
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_velocity(motorPortLeft[i],velocity*velVol*-0.5);
        pros::c::motor_move_velocity(motorPortRight[i],velocity*velVol*0.5);
    }
    while (!((abso(pros::c::motor_get_position(motorPortLeft[0])) > (abso(lastDegrees) - 5)))) {
    pros::delay(1);
    } 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_velocity(motorPortLeft[i],0);
        pros::c::motor_move_velocity(motorPortRight[i],0);
        pros::c::motor_set_brake_mode(motorPortLeft[i],MOTOR_BRAKE_BRAKE);
        pros::c::motor_set_brake_mode(motorPortRight[i],MOTOR_BRAKE_BRAKE);
        pros::c::motor_brake(motorPortLeft[i]);
        pros::c::motor_brake(motorPortRight[i]);
    }
    /* for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_absolute(motorPortLeft[i],-rotationDegrees,(-1*velocity*velVol));
        pros::c::motor_move_absolute(motorPortRight[i],rotationDegrees,(velocity*velVol));
    }  */

}

