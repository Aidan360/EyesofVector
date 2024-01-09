#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/imu.h"
#include "pros/misc.h"
#include "pros/rtos.h"
BasicChassis driveTrain; 

void ppint() {
 driveTrain.PurePursuitThread();
}
void controllerDisplay() {
  	pros::Controller master(pros::E_CONTROLLER_MASTER);
  while (true) {
    master.clear();
    c::delay(100);
    master.print(0, 1, "L: %f", sqrt(pow(driveTrain.pursuitPoints[driveTrain.lastPointIndex + 1][0] - driveTrain.position[0],2) + pow(driveTrain.pursuitPoints[driveTrain.lastPointIndex + 1][1] - driveTrain.position[1],2)));
    c::delay(100);
    master.print(1, 2, "R: %d\n",  driveTrain.PursuitKill);
    c::delay(100);
    master.print(2,1, "LPI %d\n", int(driveTrain.lastPointIndex));
    c::delay(100);
    
  }
}
void leftSide() { // testing function for now. 
//  driveTrain.leftSide(0);

}
void rightSide() {

  //driveTrain.rightSide(0);
}

void autonomous() {
   // 	pros::Controller master(pros::E_CONTROLLER_MASTER);

  	driveTrain.PursuitKill = 0;
//  Task myTask5(controllerDisplay);
 // driveTrain.tkS = 2000; 
  driveTrain.tkP = 115; // 115
  driveTrain.tkI = 0.0045; // 0.005
  driveTrain.tkD = 0.04;  // 0.04

 // driveTrain.fkS = 50; 
  driveTrain.fkP = 16.5; // 18
  driveTrain.fkI = 0.015; // 0.02
  driveTrain.fkD = 0.2; // 0.2
  
  // Random values I put in.
  driveTrain.lkS = 0;  // 2800
  driveTrain.lkV = 0;
  driveTrain.lkP = 13; // 250
  driveTrain.lkI = 0.000025;
  driveTrain.lkD = 0.00005;
  
  driveTrain.rkS = 0; //2500
  driveTrain.rkV = driveTrain.lkV;
  driveTrain.rkP = 13; // 275
  driveTrain.rkI = driveTrain.lkI;
  driveTrain.rkD = driveTrain.lkD; 
  
  driveTrain.vC = 70; // 1 
  driveTrain.aC = .75; // .25
  driveTrain.pC = 0; // .15 
  driveTrain.lookAheadRadius = 10; // radius rembmer 

	 pros::Motor intakeMotor(intakeMotor_PORT); 
   pros::ADIDigitalOut flapLeft ({{expander_PORT,EXT_flapLeft_PORT}});
   pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});
  // Task pursuitTask(ppint);
  // Task PursuitControlTask(PursuitControl);
  //driveTrain.pursuitPoints.push_back({90,90,200});
  //driveTrain.pursuitPoints.push_back({96,88,200});
  //driveTrain.pursuitPoints.push_back({100,76,200});
  pros::c::imu_reset_blocking(11);
  pros::c::imu_set_heading(11, 180);

 

//  driveTrain.leftVelocity = 0;
//  driveTrain.rightVelocity = 0;

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


//  autonomous1();

    driveTrain.turn(90);
  /*  pros::delay(250);
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
    pros::delay(250); */
/*
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
