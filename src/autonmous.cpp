#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/imu.h"
#include "pros/misc.h"
/*

void autonomous1() {
 	 pros::Motor catapultMotor (catapultMotor_PORT);
	 pros::Motor intakeMotor(intakeMotor_PORT); 
   pros::ADIDigitalOut flapLeft (EXT_flapLeft_PORT);
   pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});
   pros::ADIDigitalOut indexer ({{expander_PORT,indexer_PORT}});
  driveTrain.turn(40);
  driveTrain.goForward(50);
  flapLeft.set_value(true);
  driveTrain.turn(150);
  flapLeft.set_value(false);
  intakeMotor.move_velocity(-600);
  driveTrain.goForward(18);
  indexer.set_value(true);
  driveTrain.goForward(-12);
  intakeMotor.move_velocity(0);
  driveTrain.turn(195);
  indexer.set_value(false);
  driveTrain.goForward(50);  
  flapLeft.set_value(true);
  flapRight.set_value(true);
  driveTrain.turn(15);
  driveTrain.goForward(32);
  driveTrain.turn(325);
  driveTrain.goForward(24);
  
}
void autonomous2() {
   pros::Motor catapultMotor (catapultMotor_PORT);
	 pros::Motor intakeMotor(intakeMotor_PORT); 
   pros::ADIDigitalOut flapLeft (EXT_flapLeft_PORT);
   pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});
   pros::ADIDigitalOut indexer ({{expander_PORT,indexer_PORT}});
 
  pros::c::imu_set_heading(IMU_PORT,355);
  pros::c::imu_set_rotation(IMU_PORT, 355);
  driveTrain.goForward(50); 
  driveTrain.turn(265);
  driveTrain.goForward(-48);
  intakeMotor.move_velocity(-600);
  driveTrain.goForward(60);
  driveTrain.goForward(-12);
  driveTrain.turn(175);
  flapLeft.set_value(true);
  flapRight.set_value(true);
  driveTrain.goForward(55);
  driveTrain.turn(40);
  flapRight.set_value(false);
  driveTrain.goForward(72);
  driveTrain.turn(65);
}

 */

void autonomous() {
  	 pros::lcd::print(1,"count");
  BasicChassis driveTrain; 
  driveTrain.motorPortLeft.push_back(leftFrontMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftMiddleMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftBackMotor_PORT);
  driveTrain.motorPortRight.push_back(rightFrontMotor_PORT);
  driveTrain.motorPortRight.push_back(rightMiddleMotor_PORT);
  driveTrain.motorPortRight.push_back(rightBackMotor_PORT);
  driveTrain.wheelSize = 3.25;
  driveTrain.trackLength = 12.75; // change when you actually get the robot  */
 // driveTrain.tkS = 2000; 
  driveTrain.tkP = 115; // 115
  driveTrain.tkI = 0.0045; // 0.005
  driveTrain.tkD = 0.04;  // 0.04

 // driveTrain.fkS = 50; 
  driveTrain.fkP = 16.5; // 18
  driveTrain.fkI = 0.015; // 0.02
  driveTrain.fkD = 0.2; // 0.2
  /* PID testing logs
  PID values lowered to hopefully midigate some error 
  round 3 yippe

  Turning now, setting everything to 0 except kP 
  kP = 117
  6 turns good 
  6 turns
  6 turns 
  6 turns
  6 turns 
  kI now on
  kI = 0.02
  6 turns 
  6 turns 
  6 turns
  kD now on
  kD = 0.8
  1 turn 1 degree overshoot 
  2 turns 2 degree overshoot 
  4 turns 2 degree overshoot 
  kD = 0.6
  1 turn 2 degree overshoot 
  3 turns 2 degree overshoot
  kD = 0.2 
  1 turn 4 degree overshoot 
  1 turn 2 degree overshoot 
  2 turns 1 degree overshoot 
  6 turns 
  1 turn 3 degree overshoot 
  kD = 1
  3 turns 2 degree overshoot 
  kD = 0.01
  5 rotations 2 degree overshoot 
  6 turns
  kI is off? 
  kd off
  kI = 0.01
  4 rotations 1 degree overshoot 
  6 rotations 
  6 rotations 
  6 rotations problem is too deep rooted within the current setup. doubling movements. 
  10 rotations 2 degree overshoot 
  11 turns overshoot 2 degrees 
  12 rotations 
  12 rotations 
  12 rotations 
  12 rotations 
  kI = 0.005
  3 rotations overshoot 
  kP is off, back to kP calibration kI is off 
  kP = 117
  12 rotations 
  4 rotations 2 degree overshoot 
  4 rotations 2 degree overshoot 
  12 rotations 
  4 rotations 2 degree overshoot
  kP = 115
  12 rotations 
  7 rotations .75 overshoot 
  12 rotations 
  doubling rotations again 
  19 rotations .25 undershoot 
  10 rotations 1 degree overshoot 
  7 rotations 1 degree overshoot
  kP = 114
  24 rotations 
  17 3 degree overshoot 
  20 rotations 1 degree overshoot 
  20 rotations 2 degree overshoot 
  kP = 110
  13 rotations 1 degre undershoot 
  10 rotations .2 undershoot 
  18 rotations .3 degree undershoot 
  kP = 111 
  6 rotations 1 degree undershoot w
  24 rotations 
  24 rotations
  24 rotations 
  10 rotations 2 degree overshoot 
  7 rotations 1 degree undershoot 
  1 turn undershoot 
  4 turns 1 degree undershoot 
  2 turns 1 degree undershoot 
  kP = 112 
  4 turns 1 degree undershoot 
  4 turns 1 degree undershoot 
  8 turns 1 degree undershoot
  kP = 113
 1 turns 1 degree undershoot 
 12 turns 1 degree undershoot 
 1 turn 1 degreee undershoot 
 kP = 114
 6 turns 1 degree undershoot 
 2 turns 2 degree undershoot
 6 turns .5 degree undershoot 
 7 turns 2 degree undershoot
 kP = 116
 9 turns 2 degree undershoot 
 24 turns 
 7 turns .5 degree undershoot 
 4 turns .25 degree undershoot 
 kP = 116.5
 7 turns 2 degree overshoot 
 24 turns 
 24 turns 
 24 turns, seems good 
 kI = 0.02
 24 turns 
 6 turns 2 degree overshoot 
 24 turns 
 23 turns 2 degree undershoot 
 24 turns 
 5 turns 2 degree undershoot 
 kI = 0.025
 24 turns 
 5 turns 2 degree undershoot 
 1 turns 3 degree overshoot 
 3 turns 1 degree overshoot 
 5 turns 2 degree overshoot 
 kI = 0.0225
 1 turn 3 degree overshoot 
 4 turns 2 degree overshoot 
 kI = 0.02
 kD = 0.8
 2 turns 2 degree overshoot
 kD = 0.1
 11 turns 2 degree overshoot 
 kD is off 
 kI = 0.01
 24 turns 
 24 turns 
 6 turns .4 undershoot 
 8 turns 1 degree overshoot 
 24 turns 
 9 turns 2 degreen undershoot
 kI = 0.015
 24 turns 
 24 turns 
 12 turns .5 undershoot 
 22 turns 1 degree undershoot 
 24 turns, doubling the amount of turns to 48 
 1 turn 2 degree overshoot 
 1 turn 2 degree overshoot 
 40 turns 2 degree overshoot 
 kD = 0.1 
  1 turn 3 degree overhsoot 
  2 turns 3 degree overshoot 
 kI = 0.01
 17 turns 2 degree overshoot 
 31 turns 2 degree overshoot 
 11 turns 3 degree overshoot
 kD = 0.05
 35 turns 3 degree overshoot 
 20 turns 1 degree overshoot
 kD = 0.04
 16 turns 2 degree overshoot
 kI = 0.005
 11 turns 2 degree overshoot 
 kP = 115
 48 turns !! 
 its more than good for now time for move forward 
 kP = 17 
 2 move off by .16 
 2 move off by .24 
 2 move undershoot .24
 2 move off by .2
 kI = 0.02
 no errror but hella overshoot in movements
 kI = 0.01 
 no error but undershoot
 kI = 0.02 
 kI = 15
 overshoot still
 kI = 0.001 undershoot 1 move 
 kI = 0.005 undershoot still 
 kP = 16 underhoot a smidget 
 kP = 16.5 2 moves .2 undershoot
 kI = 0.007 .2 undershoot
 kI = 0.01 still undershoot 
 kI = 0.015
 4 moves 
 2 moves .01 undershoot 
 4 moves 
 4 moeves 
 now kD 
  kD = 0.2
  4 moves 
  4 moves good 
  4 moves good 
  now utilizing the PID turn will do square tests. basically just go in a square like movement to run more movements 
  1 square 

   */
   //driveTrain.turn(360,360);
	 pros::Motor catapultMotor (catapultMotor_PORT);
	 pros::Motor intakeMotor(intakeMotor_PORT); 
   pros::ADIDigitalOut flapLeft ({{expander_PORT,EXT_flapLeft_PORT}});
   pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});

 

    pros::c::adi_encoder_t enc = pros::c::adi_encoder_init(7,8,false);
   pros::delay(250);
    pros::c::adi_encoder_reset(enc);
    	pros::c::imu_set_heading(12, 180);
  

  //                                        AUTONOMOUS SKILLS
  //driveTrain.goForward(2);
/*  driveTrain.goForwardM(1,10);
   catapultMotor.move_velocity(-200);
    pros::delay(50000);
    driveTrain.goForward(-59); 
    driveTrain.turn(270);
    flapLeft.set_value(true);
    flapRight.set_value(true);
    driveTrain.goForward(-24); 
    driveTrain.goForward(8);
    driveTrain.turn(270);
    driveTrain.goForward(-12);
    driveTrain.turn(180);
    driveTrain.goForward(-8); */ 

 //   flapLeft.set_value(true);
 //   flapRight.set_value(true);
 //   driveTrain.turn(90);
 //   driveTrain.goForward(-24);
 //   // stage one of dementia 
 //   driveTrain.goForward(12);
 //   flapLeft.set_value(false);
 //   flapRight.set_value(false); 
    
     /*         //                          AUTONOMOUS OFFENSIVE ONE
    driveTrain.goForward(46);
    driveTrain.turn(90);
    intakeMotor.move_velocity(-200);
    driveTrain.goForward(20);
    intakeMotor.move_velocity(0);
    driveTrain.goForward(-12);
    driveTrain.turn(270);
    intakeMotor.move_velocity(200);
    driveTrain.goForward(24);
    driveTrain.turn(90);
    driveTrain.goForward(48); 
    
 */
 
  //  pros::c::imu_set_heading(IMU_PORT,45);
  //  pros::c::imu_set_rotation(IMU_PORT, 45);
    
 //                                            AUTONOMOUS DEFENSIVE ONE

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


//  autonomous1();
/*
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

  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-12);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);

  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-12);
  pros::delay(250);
  driveTrain.goForward(24);
  pros::delay(250);
  driveTrain.goForward(-24);
  pros::delay(250);
 */



  
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
