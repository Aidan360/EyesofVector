#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/imu.h"
#include "pros/misc.h"
BasicChassis driveTrain; 

void intake (){  	pros::Motor leftUtilityMotor (leftUtilityMotor_PORT);
	pros::Motor rightUtilityMotor (rightUtilityMotor_PORT);

			leftUtilityMotor.move(-127);
			rightUtilityMotor.move(127);
}
void outtake() {
    	pros::Motor leftUtilityMotor (leftUtilityMotor_PORT);
	pros::Motor rightUtilityMotor (rightUtilityMotor_PORT);
			leftUtilityMotor.move(127*0.9);
			rightUtilityMotor.move(-127*0.9);
}
void stoptake() {
    	pros::Motor leftUtilityMotor (leftUtilityMotor_PORT);
	pros::Motor rightUtilityMotor (rightUtilityMotor_PORT);
			leftUtilityMotor.move(0);
			rightUtilityMotor.move(0);
}

void turnCalibrator() {
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(270);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(5);
    pros::delay(250); 
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(270);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(5);
    pros::delay(250); 
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(270);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(5);
    pros::delay(250); 
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(270);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(5);
    pros::delay(250); 
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(270);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(5);
    pros::delay(250); 
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(270);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(5);
    pros::delay(250); 
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(270);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(5);
    pros::delay(250); 
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(270);
    pros::delay(250);
    driveTrain.turn(180);
    pros::delay(250);
    driveTrain.turn(90);
    pros::delay(250);
    driveTrain.turn(5);
    pros::delay(250); 
}
void moveCalibrator() { 
   driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
}
void offenseiveRightSide6Ball() {
 pros::c::imu_set_heading(IMU_PORT, 180-30);
  pros::ADIDigitalOut wings (wings_PORT);
  driveTrain.goForward(-72);
  driveTrain.turn(270);
  driveTrain.goForward(-24);
  
}
void autonSkills() { 
  pros::ADIDigitalOut wings (wings_PORT);
  driveTrain.goForward(-6);
  outtake();
  pros::delay(29000);
 // pros::delay(1000);
   driveTrain.goForward(-8);
   stoptake();
	pros::c::imu_set_heading(IMU_PORT, 135); // 180 for first auton, 225 for second one.  135 for skills
  pros::delay(250);
  driveTrain.goForward(5);
  driveTrain.turn(180);
  driveTrain.goForward(74);
  driveTrain.turn(270);
  driveTrain.turn(315);
  driveTrain.goForward(-23);
  driveTrain.turn(270);
  driveTrain.goForward(-24);
  driveTrain.goForward(5);
  driveTrain.turn(180);
  driveTrain.goForward(20); 
  pros::c::imu_set_heading(IMU_PORT, 90);
  pros::delay(100);
  driveTrain.goForward(-40);
  driveTrain.turn(180);
  driveTrain.turn(225);
  wings.set_value(true);
  pros::delay(250);
  driveTrain.goForward(-34);
  driveTrain.goForward(34);
  wings.set_value(false);
  driveTrain.turn(180);
  driveTrain.goForward(-24);
  driveTrain.turn(250);
  wings.set_value(true);
  pros::delay(250);
  driveTrain.goForward(-36);
  driveTrain.goForward(24);
  wings.set_value(false);
  driveTrain.turn(200);
  driveTrain.goForward(-30);
  driveTrain.turn(270+25);
    wings.set_value(true);
  pros::delay(250);
  driveTrain.goForward(-40);
  driveTrain.goForward(36); 

}
void rightSide3Ball() {
     pros::ADIDigitalOut blocker (wings_PORT);
     outtake();
     pros::delay(1000);
     intake();
      delay(500);
      driveTrain.goForward(-30);    
      driveTrain.turn(135);
      
      blocker.set_value(true);
      pros::delay(250);
      driveTrain.goForward(-20); //// Drivetrain set to 135 default, switch to 180 when done
      driveTrain.turn(90);
      driveTrain.goForward(-18);
      driveTrain.goForward(18);
      blocker.set_value(false);
      pros::delay(250);
      driveTrain.turn(180);
      driveTrain.turn(285);
			outtake();
      driveTrain.goForward(24); 
      driveTrain.goForward(-18);
       stoptake();
      /*
      driveTrain.goForward(-12);
      driveTrain.turn(145);
      driveTrain.goForward(24);
      driveTrain.turn(180);
      driveTrain.goForward(36);*/
}
void autonSkillsTurnsOnly(){
  driveTrain.turn(225);
   pros::delay(100);
  driveTrain.turn(180);
  pros::delay(100);
  driveTrain.turn(90);
  pros::delay(100);
  driveTrain.turn(30);
  pros::delay(100);
  driveTrain.turn(135);
  pros::delay(100);
  driveTrain.turn(90);
  pros::delay(100);
  driveTrain.turn(180);
  pros::delay(100);
  driveTrain.turn(90);
  pros::delay(100);
  driveTrain.turn(225);
  pros::delay(100);
                             
}
void leftSideAWP() {//135 lmao 
 pros::ADIDigitalOut wings (wings_PORT);
  outtake();
  driveTrain.goForward(24);
  stoptake();
  driveTrain.turn(180);
  outtake();
  driveTrain.goForward(8.5);
  driveTrain.goForward(-8.5);
  stoptake();
  wings.set_value(true);
  pros::delay(250);
  driveTrain.turn(135);

  driveTrain.goForward(-16);
  driveTrain.turn(90);
  wings.set_value(false);
  pros::delay(250);
driveTrain.turn(135);
driveTrain.goForward(-6);
driveTrain.turn(90);
  driveTrain.goForward(-32);
  

}

void autonomous() {
  driveTrain.motorPortLeft.push_back(leftFrontMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftMiddleMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftBackMotor_PORT);
  driveTrain.motorPortRight.push_back(rightFrontMotor_PORT);
  driveTrain.motorPortRight.push_back(rightMiddleMotor_PORT);
  driveTrain.motorPortRight.push_back(rightBackMotor_PORT);
	pros::Motor leftUtilityMotor (leftUtilityMotor_PORT);
	pros::Motor rightUtilityMotor (rightUtilityMotor_PORT);
  pros::ADIDigitalOut blocker (wings_PORT);
  

  driveTrain.wheelSize = 3.25;
  driveTrain.trackLength = 12.30402153; // change when you actually get the robot  */
  // driveTrain.tkS = 2000; 
  driveTrain.tkP = 135; // 135
  driveTrain.tkI = 0.75; // 0.75
  driveTrain.tkD = 0;  // 0

  // driveTrain.fkS = 50; 
  driveTrain.fkP = 15; // 15
  driveTrain.fkI = 0.025; // 0.025
  driveTrain.fkD = 0; // 0
  driveTrain.lookAheadRadius = 10;
  driveTrain.injectionMultipler = 4;

  //driveTrain.turn(360,360);
	//pros::Motor intakeMotor(intakeMotor_PORT); 
	leftUtilityMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	rightUtilityMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
 
 /* driveTrain.position[2] = 0;
  driveTrain.pursuitPoints.push_back({10,10,1});
  driveTrain.pursuitPoints.push_back({12,36,1});
  driveTrain.pursuitPoints.push_back({40,36,1});
  driveTrain.heading = 0;
  driveTrain.purePursuit(); */
	//pros::c::imu_set_heading(IMU_PORT, 180); // 180 for first auton, 225 for second one.  135 for skills
  //pros::delay(250)
  rightSide3Ball();
 //autonSkillsTurnsOnly();
 //turnCalibrator();
 //moveCalibrator();
 //autonSkills();
 //leftSideAWP();
///                                                           Autonomous skills code: 
  /*
 
  */




//                                                                          goal side 3 ball
	/*		leftUtilityMotor.move(-127);
			rightUtilityMotor.move(127);
      driveTrain.goForward(4);
      delay(500);
      driveTrain.goForward(-34);    
      driveTrain.turn(135);
      blocker.set_value(true);
      pros::delay(250);
      driveTrain.goForward(-12); //// Drivetrain set to 135 default, switch to 180 when done
      driveTrain.turn(90);
      driveTrain.goForward(-18);
      driveTrain.goForward(18);
      blocker.set_value(false);
      pros::delay(250);
      driveTrain.turn(180);
      driveTrain.turn(270);
			leftUtilityMotor.move(127);
			rightUtilityMotor.move(-127);
      driveTrain.goForward(18); */
 
// offesnive side Win point 
   //   intake(); 
   /*
      delay(250);
      driveTrain.goForward(24);
      driveTrain.turn(180); */
  //    outtake(); 
    //  driveTrain.goForward(6); 
    /*
   //   stoptake();
      driveTrain.goForward(-18); 
      //wings.set_value(true);
      pros::delay(250);
      driveTrain.turn(255);
      driveTrain.goForward(-12);
      driveTrain.turn(345);
      driveTrain.turn(90);
      //wings.set_value(false);
      pros::delay(250);
      driveTrain.goForward(20); 
   //   blocker.set_value(true); 
*/

 //   driveTrain.goForward(-48);

  //                                        AUTONOMOUS SKILLS
  //driveTrain.goForward(2);
 /* driveTrain.goForwardM(8,10);
   catapultMotor.move_velocity(-200);
    pros::delay(50000);
    driveTrain.goForward(4);
    driveTrain.turn(135);
    driveTrain.goForward(-59); 
    driveTrain.turn(315);
    flapLeft.set_value(true);
    flapRight.set_value(true);
    driveTrain.goForward(-24); 
    driveTrain.goForward(8);
    driveTrain.turn(270);
    driveTrain.goForward(-12);
    driveTrain.turn(180);
    driveTrain.goForward(-8);   */

 //   flapLeft.set_value(true);
 //   flapRight.set_value(true);
 //   driveTrain.turn(90);
 //   driveTrain.goForward(-24);
 //   // stage one of dementia 
 //   driveTrain.goForward(12);
 //   flapLeft.set_value(false);
 //   flapRight.set_value(false); 
    
             //                         AUTONOMOUS OFFENSIVE LEFT SIDE #1 
 /* intakeMotor.move_velocity(600);
  driveTrain.goForward(-33.75);
  driveTrain.turn(270);
 // flapLeft.set_value(true);
  flapRight.set_value(true);
  driveTrain.goForward(-18.5);
  driveTrain.turn(355);
  driveTrain.turn(270);
  intakeMotor.move_velocity(-600);
  flapRight.set_value(false);
  driveTrain.goForward(38);
  intakeMotor.move_velocity(0);
  driveTrain.goForward(-9);
  driveTrain.turn(180);
  driveTrain.goForward(40);
  driveTrain.turn(270);
  driveTrain.goForward(18.75);
  driveTrain.turn(290);
  flapLeft.set_value(true);
  pros::c::imu_set_heading(12, 90); 
  catapultMotor.move_velocity(-20);
  driveTrain.turn(280);
  flapLeft.set_value(false);
  catapultMotor.move_velocity(0);
  driveTrain.goForward(36);  
 */
  // AUTONOMUS LEFT SIDE DEFENSIVE #1 
/*
  driveTrain.goForward(-36);
  driveTrain.goForward(18);
  driveTrain.turn(180);
  flapRight.set_value(true);
  driveTrain.goForward(18);
  driveTrain.turn(225);
  flapRight.set_value(false);
  catapultMotor.move_velocity(-30);
  driveTrain.turn(185);
  catapultMotor.move_velocity(0);
  driveTrain.goForward(36);
   */

 
 
  //  pros::c::imu_set_heading(IMU_PORT,45);
  //  pros::c::imu_set_rotation(IMU_PORT, 45);
    
 //                                            AUTONOMOUS DEFENSIVE RIGHT SIDE #2 
/*
    pros::c::imu_set_heading(12, 180);
    intakeMotor.move_velocity(600);  
    driveTrain.goForward(1.5);
    driveTrain.goForward(-22); 
    driveTrain.turn(135);
    flapLeft.set_value(true);
    driveTrain.goForward(-12);
    driveTrain.turn(90);
    driveTrain.goForward(-18);
    flapLeft.set_value(false);  
    driveTrain.goForward(12);
    driveTrain.turn(270);
    intakeMotor.move_velocity(-600);
    driveTrain.goForward(13.5);

    */
    
    
  
 //   pros::c::imu_set_heading(IMU_PORT,5);
 //   pros::c::imu_set_rotation(IMU_PORT, 5);  

/*
  intakeMotor.move_velocity(600);
  driveTrain.goForward(24); 
  intakeMotor.move_velocity(0);
  driveTrain.turn(180);
  driveTrain.goForward(24);
  double auton = 8;
   if ((auton = 1)) {
  driveTrain.turn(40);
  driveTrain.goForward(50);
  flapLeft.set_value(true);
  driveTrain.turn(150);
  flapLeft.set_value(false);
  intakeMotor.move_velocity(-600);
  driveTrain.goForward(18);
  
  driveTrain.goForward(-12);
  intakeMotor.move_velocity(0);
  driveTrain.turn(195);
  
  driveTrain.goForward(50);  
  flapLeft.set_value(true);
  flapRight.set_value(true);
  driveTrain.turn(15);
  driveTrain.goForward(32);
  driveTrain.turn(325);
  driveTrain.goForward(24);
  }
  if (auton == 8) {
   catapultMotor.move_velocity(-200);
    pros::delay(4250);
    catapultMotor.move_velocity(0); 
    
    driveTrain.goForward(-96);
    flapLeft.set_value(true);
    flapRight.set_value(true);
    driveTrain.turn(90);
    driveTrain.goForward(-24);
    // stage one of dementia 
    driveTrain.goForward(12);
    flapLeft.set_value(false);
    flapRight.set_value(false);

   // driveTrain.turn()
  } */


//  autonomous1()
  

 


  
   /*
   intakeMotor.move(-127);
   driveTrain.goForwardM(60,-360);
   
  intakeMotor.move(0);
    pros::c::imu_reset_blocking(12);
   driveTrain.goForwardM(8,300);
   driveTrain.turn(90);
   driveTrain.goForwardM(48,360);
   driveTrain.turn(180);
   driveTrain.goForwardM(48,180);
   driveTrain.turn(270);
   driveTrain.goForwardM(-48,360);
   */
 // driveTrain.turnM(80, 360);
   //driveTrain.goForward(24);
  /* driveTrain.turn(74);
   pros::delay(250);
   driveTrain.turn(172);
   pros::delay(250);
   driveTrain.turn(32);
   pros::delay(250);
   driveTrain.turn(211);
   pros::delay(250); */

}
