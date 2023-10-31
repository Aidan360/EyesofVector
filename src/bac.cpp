#include "bac.hpp" 
#include "main.h"
#include "pros/adi.h"
#include "pros/llemu.h"
#include "pros/misc.hpp"
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
double pi = 3.1415926535897932384;
double radi = 1.375;
double sgn(double x) { 
    if (abso(x) == 0) {
        return(0);
    }
    else if (x > 0) { 
        return (1);
    }
    else {
        return(-1);
    }
}
void BasicChassis::goForward(double inch) {
    double error = 0;
    double lastError = 0;
    integral = 0;
    double count = 0;
    double counter = 50; 
    pros::c::adi_encoder_t enc = pros::c::adi_encoder_init(8,7,true);
    error = (inch/(radi*pi))*360/2 - pros::c::adi_encoder_get(enc);  
    while (abs(error) > 10.41741446) { 
    error = (inch/(radi*pi))*360/2  - pros::c::adi_encoder_get(enc);  
//    pros::lcd::print(0, "Obama %d\n", (pros::c::adi_encoder_get(enc) * 3.25 / 360));
    pros::lcd::print(0, "Odom Value: %d\n",int((error/360)*pi*radi*100));
    integral = integral + error; 
    derivative = error - lastError;
    double output = fkP*error + fkI*integral + fkD*derivative + sgn(error)*fkS ; 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],output * -1);
        pros::c::motor_move_voltage(motorPortRight[i],output * -1);
    }
    lastError = error; 
    if (int(pros::c::motor_get_actual_velocity(motorPortLeft[1])) == 0) {
        count = count + 1;
    }
    else {
        count = 0;
    } 
    if (counter < count) {
        break;
    } 
    pros::delay(10);
    }  
        // pros::c::adi_encoder_reset(enc);
        pros::lcd::print(1, "done %d", int((error * 2.75 / 360)*2*10)); 

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
    double count = 0;
    double counter = 10; 
    while ((abso(error) > 0.25)) { 
    error = degree - pros::c::imu_get_heading(12);  
    pros::lcd::print(0, "Heading %f", pros::c::imu_get_heading(12));
    pros::lcd::print(3,"count %f", count);
    integral = integral + error; 
    derivative = error - lastError;
    output = tkP*error + tkI*integral + tkD*derivative + sgn(error)*tkS; 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],-output);
        pros::c::motor_move_voltage(motorPortRight[i],output);
    }

    if (int(pros::c::motor_get_actual_velocity(motorPortLeft[1])) == 0) {
        count = count + 1;
    }
    else {
        count = 0;
    } 
    if (counter < count) {
        break;
    }  
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

int BasicChassis::calibrator(float inputP, float inputI, float inputD, float inputS) {
    bool kScal;
    bool kPcal;
    bool kIcal;
    bool kDcal;
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    while (true) {
        if (pros::battery::get_capacity() <= 30) {
            master.rumble("..--..--");
            pros::lcd::print(0, "PID Values %f", pros::c::imu_get_heading(12));
        }



    }
    return(1);
}