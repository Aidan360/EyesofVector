#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/misc.h"
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
  bool flapExtend = false;
  bool climbPTO = false;
  bool indexerd = false; 
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	 pros::lcd::print(2,"count");
	
	while (true) {
	
		if (master.get_digital(DIGITAL_R2)) {
      		if (flapExtend == false) {
				flapLeft.set_value(false);
				flapRight.set_value(true);	
				flapExtend = true;
				pros::delay(250);
			} else {
				flapLeft.set_value(true);
				flapRight.set_value(false);
				flapExtend = false;
				pros::delay(250);
			}
    	}
		if (master.get_digital(DIGITAL_B)) {
      		if (indexerd == false) {
				indexer.set_value(true);
				indexerd = true;
				pros::delay(250);
			} else {
				indexer.set_value(false);
				indexerd = false;
				pros::delay(250);
			}
		}
		 
		
		if (cataLimit.get_value() == 0) { 
			catapultMotor.move_velocity(-120); 
		}
		else if (master.get_digital(DIGITAL_R1)) {
			catapultMotor.move(-127);
		}  
		else if (cataLimit.get_value() == 1) { 
			catapultMotor.move(0);
			catapultMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
			catapultMotor.brake();
		}

		

		if (master.get_digital(DIGITAL_L1)) {
			intakeMotor.move(127);
		}
		else if (master.get_digital(DIGITAL_L2)) {
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
