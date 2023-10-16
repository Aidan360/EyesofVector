#include "bac.hpp" 
#include "main.h"
#include "pros/adi.h"
#include "pros/llemu.h"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "math.h"
#include "initialize.hpp"
double abso(double x) {
    if (0 > x) {
        return(x * -1);
    }
    else {
        return(x);
    }
} 
void BasicChassis::goForward(double inch) {
    double error;
    double lastError;
    pros::c::adi_encoder_t enc = pros::c::adi_encoder_init(encoderTop_PORT,encoderBottom_PORT,false);
    while (abs(error) > 0) { 
    error = inch - pros::c::adi_encoder_get(enc);  
    integral = integral + error; 
    derivative = error - lastError;
    double output = tkP*error + tkI*integral + tkD*derivative; 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(-motorPortLeft[i],output);
        pros::c::motor_move_voltage(-motorPortRight[i],output);
    }
    lastError = error; 
    pros::delay(10);
    }  

}
void BasicChassis::goForwardM(double distance, double velocity) { // Horizontal 
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
void BasicChassis::turn(double degree) {
    double error = degree - pros::c::imu_get_heading(12);
    double lastError = 0;
    double output;
    integral = 0;
    while ((abso(error) > 0.5)) { 
    error = degree - pros::c::imu_get_heading(12);  
    pros::lcd::print(0, "Balls %f", pros::c::imu_get_heading(12));
    integral = integral + error; 
    derivative = error - lastError;
    output = tkP*error + tkI*integral + tkD*derivative; 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],-output);
        pros::c::motor_move_voltage(motorPortRight[i],output);
    }
    lastError = error; 
    pros::delay(10);
    }  

    pros::lcd::print(1, "done %f", pros::c::imu_get_heading(12)); 

}
void BasicChassis::turnM(double degrees, double velocity) {
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

