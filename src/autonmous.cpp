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
  driveTrain.tkP = 117; // 120
  driveTrain.tkI = 0.02; // 0.025
  driveTrain.tkD = 0.8;  // 0.8

 // driveTrain.fkS = 50; 
  driveTrain.fkP = 17; // 18
  driveTrain.fkI = 0.02; // 0.02
  driveTrain.fkD = 0.2; // 0.2
  /* PID testing logs
  PID values lowered to hopefully midigate some error 
  round 3 yippe
  kP117 
  kI0.025 
  kd0.8
  
  3 degree overshoot 
  6 turns 
  6 turns 

  kI = 0.02
  6 turns 

   forward PID v
  */
   //driveTrain.turn(360,360);
	 pros::Motor catapultMotor (catapultMotor_PORT);
	 pros::Motor intakeMotor(intakeMotor_PORT); 
   pros::ADIDigitalOut flapLeft (EXT_flapLeft_PORT);
   pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});

/*   
    pros::c::imu_reset_blocking(IMU_PORT);
    pros::c::imu_set_heading(IMU_PORT,5);
    pros::c::imu_set_rotation(IMU_PORT, 5); */
    /*if(pros::c::imu_get_heading(IMU_PORT) > 6) {
      pros::c::imu_set_heading(IMU_PORT,5);

    } */
    pros::c::adi_encoder_t enc = pros::c::adi_encoder_init(7,8,false);
   pros::delay(500);
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
    
    /*                                    AUTONOMOUS OFFENSIVE ONE
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
    driveTrain.goForward(48); */
    
    /*                                    
    
    */
 
  //  pros::c::imu_set_heading(IMU_PORT,45);
  //  pros::c::imu_set_rotation(IMU_PORT, 45);
    
 //                                            AUTONOMOUS DEFENSIVE ONE

    pros::c::imu_set_heading(12, 180);
    intakeMotor.move_velocity(600);  
    driveTrain.goForward(2);
    driveTrain.goForward(-18); 
    driveTrain.turn(135);
    flapLeft.set_value(true);
    driveTrain.goForward(-9);
  

    driveTrain.turn(90);
    //flapLeft.set_value(std::int32_t value)
    driveTrain.goForward(-14);
    driveTrain.goForward(12);
    driveTrain.turn(270);
    intakeMotor.move_velocity(-600);
    driveTrain.goForward(13);
    driveTrain.goForward(12);
    
  
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
    pros::delay(4500);
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

  /*driveTrain.turn(90);
  pros::delay(500);
  driveTrain.turn(180);
  pros::delay(500);
  driveTrain.turn(270);
  pros::delay(500);
  driveTrain.turn(180);
  pros::delay(500);
  driveTrain.turn(90);
  pros::delay(500);
  driveTrain.turn(5);
  pros::delay(500); */
/*
  driveTrain.goForward(24);
  pros::delay(500);
  driveTrain.goForward(-12);
  pros::delay(500);
  driveTrain.goForward(24);
  pros::delay(500);
  driveTrain.goForward(-24);
  pros::delay(500);

  driveTrain.goForward(24);
  pros::delay(500);
  driveTrain.goForward(-12);
  pros::delay(500);
  driveTrain.goForward(24);
  pros::delay(500);
  driveTrain.goForward(-24);
  pros::delay(500);
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
   pros::delay(500);
   driveTrain.turn(172);
   pros::delay(500);
   driveTrain.turn(32);
   pros::delay(500);
   driveTrain.turn(211);
   pros::delay(500); */

}
