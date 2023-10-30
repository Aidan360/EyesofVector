#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/imu.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
    pros::Motor leftFrontMotor (leftFrontMotor_PORT);
    pros::Motor leftMiddleMotor (leftMiddleMotor_PORT);
    pros::Motor leftBackMotor (leftBackMotor_PORT);
    pros::Motor rightFrontMotor (rightFrontMotor_PORT);
    pros::Motor rightMiddleMotor (rightMiddleMotor_PORT);
    pros::Motor rightBackMotor (rightBackMotor_PORT);
    pros::Motor catapultMotor (catapultMotor_PORT);
	pros::Motor intakeMotor(intakeMotor_PORT);
    //pros::ADIDigitalOut climbingPTO (climbingPTO_PORT);
     pros::ADIDigitalOut flapLeft (EXT_flapLeft_PORT);
    pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});
	pros::ADIDigitalIn cataLimit ({{expander_PORT,EXT_cataLimit_PORT}});
	pros::ADIDigitalOut indexer ({{expander_PORT,indexer_PORT}});
void disabled() {}

void competition_initialize() {}

  float left;
  float right;
  float power;
  float turn;
  bool flapExtendR = false;
  bool flapExtendL = false;
  bool climbPTO = false;
  bool indexerd = false;
  int mode = 2; 
  bool reciever = false;  

  
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	 pros::lcd::print(2,"count");

	while (true) {
//	  pros::lcd::print(0, "Head %f", pros::c::imu_get_heading(12));
		if (master.get_digital(DIGITAL_RIGHT)) {
      		if (flapExtendL == false) {
				flapLeft.set_value(true);
				flapRight.set_value(true);	
				flapExtendL = true;
				flapExtendR = true;
				pros::delay(250);
			} else {
				flapLeft.set_value(false);
				flapRight.set_value(false);
				flapExtendL = false;
				flapExtendR = false;
				pros::delay(250);
			}
    	}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      		if (flapExtendL == false) {
				flapLeft.set_value(true);
				flapExtendL = true;
				pros::delay(250);
			} else {
				flapLeft.set_value(false);
				flapExtendL = false;
				pros::delay(250);
			}
    	}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      		if (flapExtendL == false) {
				flapRight.set_value(true);
				flapExtendR = true;
				pros::delay(250);
			} else {
				flapRight.set_value(false);
				flapExtendR = false;
				pros::delay(250);
			}
    	}
		/*if (master.get_digital(DIGITAL_B)) {
      		if (indexerd == false) {
				indexer.set_value(true);
				indexerd = true;
				pros::delay(250);
			} else {
				indexer.set_value(false);
				indexerd = false;
				pros::delay(250);
			}
		} */
		 /*
		

		else if (master.get_digital(DIGITAL_R1)) {
			catapultMotor.move(-127);
		}  
		else if (cataLimit.get_value() == 1) { 
			catapultMotor.move(0);
			catapultMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
			catapultMotor.brake();
		} 
			*/
		
		pros::Controller master(pros::E_CONTROLLER_MASTER);

		
        if (master.get_digital_new_press(DIGITAL_Y)) {
            mode = 1;
        }
        if (master.get_digital_new_press(DIGITAL_B)) {
            mode = 2;
        }
        if (master.get_digital_new_press(DIGITAL_DOWN)) {
            mode = 3; 
        }
		if (master.get_digital(DIGITAL_L1)) {
			if (reciever == true) {
				reciever = false; 
			}
			else {
				reciever = true; 
			}
		
		}
        if (mode == 1) { // Base Catapult Down
            if (pros::c::ext_adi_digital_read(expander_PORT,EXT_cataLimit_PORT) == false) { 
                catapultMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
				catapultMotor.move_velocity(-100);
            }   else {
				catapultMotor.brake();
			}
        } else if (mode == 2) { // catapult up 
            catapultMotor.set_brake_mode(MOTOR_BRAKE_COAST);
			catapultMotor.brake();
        } else if (mode == 3) { // catapult automatic 
            catapultMotor.move_velocity(-200); 
        } else if (reciever == true) {
  			catapultMotor.move_velocity(-200);
        } else {
            catapultMotor.move_velocity(0);
        }

		if (master.get_digital(DIGITAL_R1)) {
			intakeMotor.move(127);
		}
		else if (master.get_digital(DIGITAL_R2)) {
			intakeMotor.move(-127);
		}
		else {
			intakeMotor.move(0);
		}
		/*
		if (master.get_digital(DIGITAL_B)){
      		if (climbPTO == false) {
				climbingPTO.set_value(true);
			} else {
				climbingPTO.set_value(false);
			}
		} */
		power = master.get_analog(ANALOG_LEFT_Y);
		turn = master.get_analog(ANALOG_RIGHT_X);
		left = power + turn;
		right = power - turn;
		leftFrontMotor.move(-1*left); // Conners Move
		leftMiddleMotor.move(-1*left);
		leftBackMotor.move(-1*left);
		rightFrontMotor.move(-1*right);
		rightMiddleMotor.move(-1*right);
		rightBackMotor.move(-1*right);
		pros::delay(10);
}

}