#include "main.h"
#include "initialize.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
    pros::Motor leftFrontMotor (leftFrontMotor_PORT);
    pros::Motor leftMiddleMotor (leftMiddleMotor_PORT);
    pros::Motor leftBackMotor (leftBackMotor_PORT);
    pros::Motor rightFrontMotor (rightFrontMotor_PORT);
    pros::Motor rightMiddleMotor (rightMiddleMotor_PORT);
    pros::Motor rightBackMotor (rightBackMotor_PORT);
    pros::Motor catapultMotor (catapultMotor_PORT);
	pros::Motor intakeMotor(intakeMotor_PORT);
    pros::ADIDigitalOut climbingPTO (climbingPTO_PORT);
    pros::ADIDigitalOut flapLeft ({{expander_PORT,EXT_flapLeft_PORT}});
    pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});
void disabled() {}

void competition_initialize() {}

void autonomous() {}

  float left;
  float right;
  float power;
  float turn;
  bool flapExtend = false;
  bool climbPTO = false;
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	while (true) {
		if (master.get_digital(DIGITAL_R2)) {
      		if (flapExtend == false) {
				flapLeft.set_value(true);
				flapRight.set_value(true);	
			} else {
				flapLeft.set_value(false);
				flapRight.set_value(false);
			}
    	}
		if (master.get_digital(DIGITAL_R1)) {
			catapultMotor.move(127);
		} // should work ???
		if (master.get_digital(DIGITAL_L1)) {
			intakeMotor.move(127);
		}
		if (master.get_digital(DIGITAL_L2)) {
			intakeMotor.move(-127);
		}
		if (master.get_digital(DIGITAL_B)){
      		if (climbPTO == false) {
				climbingPTO.set_value(true);
			} else {
				climbingPTO.set_value(false);
			}
		}
		power = master.get_analog(ANALOG_LEFT_Y);
		turn = master.get_analog(ANALOG_RIGHT_X);
		left = power + turn;
		right = power - turn;
		leftFrontMotor.move(left); // Conners Move
		leftMiddleMotor.move(left);
		leftBackMotor.move(left);
		rightFrontMotor.move(right);
		rightMiddleMotor.move(right);
		rightBackMotor.move(right);
		pros::delay(250);
	}
}
