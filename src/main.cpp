#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/imu.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "launcher.hpp"
    pros::Motor leftFrontMotor (leftFrontMotor_PORT);
    pros::Motor leftMiddleMotor (leftMiddleMotor_PORT);
    pros::Motor leftBackMotor (leftBackMotor_PORT);
    pros::Motor rightFrontMotor (rightFrontMotor_PORT);
    pros::Motor rightMiddleMotor (rightMiddleMotor_PORT);
    pros::Motor rightBackMotor (rightBackMotor_PORT);
	pros::Motor intakeMotor(intakeMotor_PORT);
	pros::Motor spinner(flyWheelMotor_PORT);
    //pros::ADIDigitalOut climbingPTO (climbingPTO_PORT);s
	pros::ADIDigitalIn cataLimit ({{expander_PORT,EXT_cataLimit_PORT}});
	pros::ADIDigitalOut indexer ({{expander_PORT,indexer_PORT}});
	pros::ADIDigitalOut wings (wings_PORT);
	pros::ADIDigitalOut blocker (blocker_PORT);
void disabled() {
	globalRPM = 0;
	driveTrain.PursuitKill = 1;
//	driveTrain.leftVelocity = 0;
//	driveTrain.rightVelocity = 0;
}

void competition_initialize() {}

  float left;
  float right;
  float power;
  float turn;
  bool climbPTO = false;
  bool indexerd = false;
  int mode = 2; 
  bool reciever = false;  
	bool flaps = false; 
  bool block2 = false; 
void opcontrol() {
	
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	 pros::lcd::print(2,"count");

	while (true) {
		intakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		
		if (master.get_digital_new_press(DIGITAL_L1)) {
			if(flaps == false) {
				wings.set_value(true);
				flaps = true;
			}
			else {
				wings.set_value(false);
				flaps = false; 
			}
		}
		if (master.get_digital_new_press(DIGITAL_L2)) {
			if(block2 == false) {
				blocker.set_value(true);
				block2 = true;
			}
			else {
				blocker.set_value(false);
				block2 = false; 
			}
		}
		
//	  pros::lcd::print(0, "Head %f", pros::c::imu_get_heading(12));
		

		if (master.get_digital_new_press(DIGITAL_B)) {
            //globalRPM = 0;
			spinner.move(-127);
			
        }
		else if (master.get_digital_new_press(DIGITAL_DOWN)) {
            //globalRPM = 2000;
			spinner.move(0);
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