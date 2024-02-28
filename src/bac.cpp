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
    return(sqrt(pow(x+0,2)));
} 
double pi = 3.1415926535897932384;
double radi = 3.25/2;
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
    pros::c::motor_tare_position(motorPortLeft[0]);
    pros::c::motor_tare_position(motorPortRight[0]);
    pros::c::motor_tare_position(motorPortLeft[1]);
    pros::c::motor_tare_position(motorPortRight[1]);
    pros::c::motor_tare_position(motorPortLeft[2]);
    pros::c::motor_tare_position(motorPortRight[2]);   
    error = 11;
    double lastError = 0;
    integral = 0;
    double count = 0;
    double counter = 150; 
    fail = false;
    int intError = sgn(error);
     error = (inch/(radi*pi))*360/2  - (pros::c::motor_get_position(motorPortLeft[0]) + pros::c::motor_get_position(motorPortRight[0])) * 0.5 * 0.6 * -1; 
    while (abs(error) > 8) { 
     error = (inch/(radi*pi))*360/2  - (pros::c::motor_get_position(motorPortLeft[0]) + pros::c::motor_get_position(motorPortRight[0])) * 0.5 * 0.6 * -1; 
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
    if (error == lastError) {
        count = count+1;
    } 
    else {
        count = 0;
    } 
    if (counter < count) {
        fail = true;    
        break;
    } 
    if (sgn(error) != intError) {
        integral = 0;
        intError = sgn(error);
    }
    pros::delay(10);
    }  
        // pros::c::adi_encoder_reset(enc);
        pros::lcd::print(1, "done %d", int((error * 2.75 / 360)*2*10)); 
        pros::c::motor_move_voltage(motorPortLeft[0],0);
        pros::c::motor_move_voltage(motorPortRight[0],0);
        pros::c::motor_move_voltage(motorPortLeft[1],0);
        pros::c::motor_move_voltage(motorPortRight[1],0);
        pros::c::motor_move_voltage(motorPortLeft[2],0);
        pros::c::motor_move_voltage(motorPortRight[2],0);

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
    error = degree - pros::c::imu_get_heading(IMU_PORT);
    int intError = sgn(error);
    fail = false;
    double lastError = 0;
    double output;
    integral = 0;
    double count = 0;
    double counter = 50; 
    while ((abso(error) > 1)) { 
    error = degree - pros::c::imu_get_heading(IMU_PORT);  
    pros::lcd::print(0, "Heading %f", pros::c::imu_get_heading(IMU_PORT));
    pros::lcd::print(3,"count %f", count);
    integral = integral + error; 
    derivative = error - lastError;
    output = tkP*error + tkI*integral + tkD*derivative + sgn(error)*tkS; 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],-output);
        pros::c::motor_move_voltage(motorPortRight[i],output);
    }
    lastError = error;
    if (int(pros::c::motor_get_actual_velocity(motorPortLeft[1])) == 0) {
        count = count + 1;
    }
    else {
        count = 0;
    }  
    if (counter < count) {
        fail = true;
       break;
    }  
    if (sgn(error) != intError) {
        integral = 0;
        intError = sgn(error);
    }
    pros::delay(10);
    }  

        pros::c::motor_move_voltage(motorPortLeft[0],0);
        pros::c::motor_move_voltage(motorPortRight[0],0);
        pros::c::motor_move_voltage(motorPortLeft[1],0);
        pros::c::motor_move_voltage(motorPortRight[1],0);
        pros::c::motor_move_voltage(motorPortLeft[2],0);
        pros::c::motor_move_voltage(motorPortRight[2],0);
    pros::lcd::print(1, "done %f", pros::c::imu_get_heading(IMU_PORT)); 

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



void BasicChassis::goForwardO(double distanceDes, double velocity) { 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
         pros::c::motor_tare_position(motorPortLeft[i]);
         pros::c::motor_tare_position(motorPortRight[i]);
    }
    double distLeft = distanceDes - distance; 
    position[0] = 0; 
    position[1] = 0;
    while (distLeft > 0.1){
        distLeft = distanceDes - distance; 
        if (distLeft > distanceDes * 0.9) { 
            pros::c::motor_move_velocity(motorPortLeft[0],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[0],velocity*velVol*0.5*0.1);
            pros::c::motor_move_velocity(motorPortLeft[1],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[1],velocity*velVol*0.5*0.1);
            pros::c::motor_move_velocity(motorPortLeft[2],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[2],velocity*velVol*0.5*0.1);
        }
        else if (distanceDes * 0.9 > distLeft > distanceDes * 0.1) {
            pros::c::motor_move_velocity(motorPortLeft[0],velocity*velVol*-0.5);
            pros::c::motor_move_velocity(motorPortRight[0],velocity*velVol*0.5);
            pros::c::motor_move_velocity(motorPortLeft[1],velocity*velVol*-0.5);
            pros::c::motor_move_velocity(motorPortRight[1],velocity*velVol*0.5);
            pros::c::motor_move_velocity(motorPortLeft[2],velocity*velVol*-0.5);
            pros::c::motor_move_velocity(motorPortRight[2],velocity*velVol*0.5);
        }
        else if (distLeft > distanceDes * 0.1) { 
            pros::c::motor_move_velocity(motorPortLeft[0],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[0],velocity*velVol*0.5*0.1);
            pros::c::motor_move_velocity(motorPortLeft[1],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[1],velocity*velVol*0.5*0.1);
            pros::c::motor_move_velocity(motorPortLeft[2],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[2],velocity*velVol*0.5*0.1);
        }
        else { 
            pros::c::motor_move_velocity(motorPortLeft[0],0);
            pros::c::motor_move_velocity(motorPortRight[0],0);
            pros::c::motor_move_velocity(motorPortLeft[1],0);
            pros::c::motor_move_velocity(motorPortRight[1],0);
            pros::c::motor_move_velocity(motorPortLeft[2],0);
            pros::c::motor_move_velocity(motorPortRight[2],0);
        }
    }
}
void BasicChassis::turnO(double degrees, double velocity) { 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
         pros::c::motor_tare_position(motorPortLeft[i]);
         pros::c::motor_tare_position(motorPortRight[i]);
    }
    double degLeft = degrees - heading; 
    position[0] = 0; 
    position[1] = 0;
    while (degLeft > 0.1){
        degLeft = degrees - heading; 
        if (degLeft > degrees * 0.9) { 
            pros::c::motor_move_velocity(motorPortLeft[0],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[0],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortLeft[1],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[1],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortLeft[2],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[2],velocity*velVol*-0.5*0.1);
        }
        else if (degrees * 0.9 > degLeft > degrees * 0.1) {
            pros::c::motor_move_velocity(motorPortLeft[0],velocity*velVol*-0.5);
            pros::c::motor_move_velocity(motorPortRight[0],velocity*velVol*-0.5);
            pros::c::motor_move_velocity(motorPortLeft[1],velocity*velVol*-0.5);
            pros::c::motor_move_velocity(motorPortRight[1],velocity*velVol*-0.5);
            pros::c::motor_move_velocity(motorPortLeft[2],velocity*velVol*-0.5);
            pros::c::motor_move_velocity(motorPortRight[2],velocity*velVol*-0.5);
        }
        else if (degLeft > degrees * 0.1) { 
            pros::c::motor_move_velocity(motorPortLeft[0],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[0],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortLeft[1],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[1],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortLeft[2],velocity*velVol*-0.5*0.1);
            pros::c::motor_move_velocity(motorPortRight[2],velocity*velVol*-0.5*0.1);
        }
        else { 
            pros::c::motor_move_velocity(motorPortLeft[0],0);
            pros::c::motor_move_velocity(motorPortRight[0],0);
            pros::c::motor_move_velocity(motorPortLeft[1],0);
            pros::c::motor_move_velocity(motorPortRight[1],0);
            pros::c::motor_move_velocity(motorPortLeft[2],0);
            pros::c::motor_move_velocity(motorPortRight[2],0);
        }
    }
}


int BasicChassis::calibrator(float inputP, float inputI, float inputD, float inputS,bool type) { // turn = 0, forward = 1
    bool kScal;
    bool kPcal;
    bool kIcal;
    bool kDcal;
    int mode;
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    while (true) {
        if (pros::battery::get_capacity() <= 30) {
            master.rumble("..--..--");
            pros::lcd::print(0, "PID Values %f");
            pros::lcd::print(1, "kP%f", ckP);
            pros::lcd::print(2, "kI%f", ckI);
            pros::lcd::print(3, "kD%f", ckD);
            pros::lcd::print(4, "kS%f", ckS);       
        }
        if (pros::c::motor_get_temperature(1) >= 50) {
            master.rumble("----....");
            pros::lcd::print(0, "PID Values %f");
            pros::lcd::print(1, "kP%f", ckP);
            pros::lcd::print(2, "kI%f", ckI);
            pros::lcd::print(3, "kD%f", ckD);
            pros::lcd::print(4, "kS%f", ckS);       
        }
        
        if (kScal == true) { // don't understand this alexis its just my code 
            if (kPcal == true) {
                if (kIcal == true) {
                    if (kDcal == true) {
                        break;
                    } else {
            
                    }
                } else {
        
                }
            } else {
                if (type == 0) {
                    tkS = inputS;
                    tkP = 0;
                    tkI = 0;
                    tkD = 0;
                    while (true) {
                        double output = tkS; 
                        double count; 
                        for (int i = 0; i < std::size(motorPortLeft); ++i) {
                                pros::c::motor_move_voltage(motorPortLeft[i],-output);
                                pros::c::motor_move_voltage(motorPortRight[i],output);
                        }
                        pros::delay(500);
                        if (int(pros::c::motor_get_actual_velocity(motorPortLeft[1])) == 0) {
                            tkS = tkS + 0.5;
                        }

                    }
                }
                
            }
        }       

    


        



    }
    return(1);
}
