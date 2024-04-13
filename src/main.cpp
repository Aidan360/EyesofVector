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
	pros::Motor leftUtilityMotor (leftUtilityMotor_PORT);
	pros::Motor rightUtilityMotor (rightUtilityMotor_PORT);
    //pros::ADIDigitalOut climbingPTO (climbingPTO_PORT);s
	pros::ADIDigitalOut wings (wings_PORT);
	pros::ADIDigitalOut PTO (PTO_PORT);
	pros::ADIDigitalOut clawRelease (clawRelease_PORT);
	pros::Optical ColorSensor (Color_PORT);
void disabled() {

//	driveTrain.PursuitKill = 1;
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
	bool jammed = false; 
  bool block2 = false;
  bool releaseA = false; 

  int colorControl = 0;  
  bool jitter = false; 
  bool jitter2 = false;
void opcontrol() {
			    pros::Optical ColorSensor (Color_PORT);
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	 pros::lcd::print(2,"count");
	leftUtilityMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	rightUtilityMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);

	while (true) {
	 pros::lcd::print(2,"colorControl %d", int(ColorSensor.get_hue()));

		if (master.get_digital_new_press(DIGITAL_L1)) {
			if(jammed == false) {
				wings.set_value(true);
				jammed = true;
			}
			else {
				wings.set_value(false);
				jammed = false; 
			}
		}
		if (master.get_digital_new_press(DIGITAL_B)) {
			if(block2 == false) {
				PTO.set_value(true);
				block2 = true;
			}
			else {
				PTO.set_value(false);
				block2 = false; 
			}   
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			if(releaseA == false) {
				clawRelease.set_value(true);
				releaseA = true;
			}
			else {
				clawRelease.set_value(false);
				releaseA = false; 
			}   
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
			if(jitter == false) {
				jitter = true; 
			}
			else {
				jitter = false; 
			}   
		}
		
		
		if (jitter == true) {
			if(jitter2 == false) {
				leftFrontMotor.move(6000); // Conners Move
				leftMiddleMotor.move(6000);
				leftBackMotor.move(6000);
				rightFrontMotor.move(-6000);
				rightMiddleMotor.move(-6000);
				rightBackMotor.move(-6000);
			}
			else {
				leftFrontMotor.move(-6000); // Conners Move
				leftMiddleMotor.move(-6000);
				leftBackMotor.move(-6000);
				rightFrontMotor.move(6000);
				rightMiddleMotor.move(6000);
				rightBackMotor.move(6000);
			}
		}
		
//	  pros::lcd::print(0, "Head %f", pros::c::imu_get_heading(12));
		



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
		left = power - turn;
		right = power + turn;
		leftFrontMotor.move(left); // Conners Move
		leftMiddleMotor.move(left);
		leftBackMotor.move(left);
		leftUtilityMotor.move(left);
		rightFrontMotor.move(right);
		rightMiddleMotor.move(right);
		rightBackMotor.move(right);
		rightUtilityMotor.move(right);


		if (master.get_digital(DIGITAL_R1)) {
			leftUtilityMotor.move(-127*0.9);
			rightUtilityMotor.move(127*0.9);
		}
		else if (master.get_digital(DIGITAL_R2)) {
			leftUtilityMotor.move(127);
			rightUtilityMotor.move(-127);
		}
		else {
			leftUtilityMotor.move(0);
			rightUtilityMotor.move(0);
		}
		pros::delay(100);
}
}