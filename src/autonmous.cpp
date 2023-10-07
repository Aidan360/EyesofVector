#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/misc.h"
using nameSpace vectorR {


    /*  driveTrain.motorPortLeft.push_back(leftFrontMotor_PORT);
      driveTrain.motorPortLeft.push_back(leftMiddleMotor_PORT);
      driveTrain.motorPortLeft.push_back(leftBackMotor_PORT);
      driveTrain.motorPortRight.push_back(rightFrontMotor_PORT);
      driveTrain.motorPortRight.push_back(rightMiddleMotor_PORT);
      driveTrain.motorPortRight.push_back(rightBackMotor_PORT);
    */driveTrain.rpm == 360; 
      driveTrain.wheelSize = 3.25;
      driveTrain.trackLength = 13.75; // change when you actually get the robot  */

void autonomous() {
 //  driveTrain.goForward(40,360);
	 pros::Motor catapultMotor (catapultMotor_PORT);
	 pros::Motor intakeMotor(intakeMotor_PORT); 
   intakeMotor.move(-127);
	pros::delay(2500);
   intakeMotor.move(127);
	pros::delay(2500);
  // driveTrain.goForward(20,360);
  // driveTrain.turn(1000,360); 
}
}