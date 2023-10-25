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
  driveTrain.tkP = 120; // 135
  driveTrain.tkI = 0.025; // 0.025
  driveTrain.tkD = 0.8;  // 0.9

 // driveTrain.fkS = 50; 
  driveTrain.fkP = 18;
  driveTrain.fkI = 0.02;
  driveTrain.fkD = 0.2;
  /* 
  PID testing round two baby 
  I'll start by redoing all of turning 
  
  Tribals of 4 sets of turning 
  kP = 127 3 test 
  all 5 rotations random large turn fixed by manually setting heading to 0 before first movement
  all 5 rotations 
  all 5 rotations 
  Switching margin of error to +- 1 to 0.5
  kp = 127 
  2 rotations undershoot 0.9 degrees 
  1 rotation undershot 2 degrees 
  1 rotation 2 degree undershot 
  kp = 128
  4 rotations 1 degree overshoot 
  3 rotations 2 degree undershoot 
  1 rotation 2 degree undershoot 
  4 rotations 1 degree overshoot 
  1 rotattion 1 degree undershoot
  kp = 129 
  4 rotations .5 degree overshoot 
  5 rotations 1 large rotation full set tho  Theres been a lot of code issues, Im going to have the program guarentee it starts from 0 degrees
  3 rotations but tile moved while robots spinning, adding another weight to the actual testing area so tiles don't move
  bringing back 360 degree rotation. Program is now 0 - 90 - 180 - 270 - 355 - 270 - 180 - 90 - 5 
  1 rotation 1 degree undershoot 
  1 rotation 2 degree undershoot
  1 rotation 1 degree undershoot  consistently seeing auto 360 errors, setting starting degrees to 1
  kP = 130
  1 rotation 2 degree undershoot
  2 rotations1 degreen undershoot 
  2 rotations undershoot

  Robot continously thinks its 360 degrees its really god damn annoying doing 5 degree starter 

  1 rotation 2 degree undershoot 
  2 rotation 2 degree undershoot
  1 rotation 2 degree undershoot 
  5 rotations .4 degree overshoot
  5 rotations .7 degree overshoot 
  4 roations 2 degree undershoot

  kP = 135
  5 rotations 1 large rotation  fixed large rotation 
  5 rotations 2 degree undershoot 
  7 rotations 1 degree undershoot
  3 rotations .5 degree overshoot
  8 rotations Full turns 
  8 rotations 
  8 rotations 

  kp 135 new Rotational kP onto kD 

  now adding a second set of movement, using controllers autonmous skills to test 

  kD = 0.9 
  all 16 rotations 
  all 16 rotations 
  changing error to from +-0.5 to +-0.25
  8 rotations 0.6 undershoot 
  16 rotations 
  16 rotations 
  
  kD is good onto kI 

  kI = 0.02
  1 rotation 1 degree overshoot 
  3 rotations 1 degree undershoot 
  10 rotations 1 degree overshoot 
  2 rotations 2 degree overshoot 
  7 rotations 2 degree unvershoot
  5 rotations 2 degree undershoot 
  7 rotations 3 degree undersho0t 
  14 rotations 1 degree undershoot

  kI = 0.03
  6 rotations 0.5 degree overshoot, 
  2 rotations 1 degree overshoot 


  Added kS feed forward controller, basically prevents the robot from any overshoot or undershoot by introducing a 
  baseline minimum movement if kP kI or kD aren't correcting the robots movement. It should only screw with the 
  kP varaible so recalibration needs to be done on just that. 
  
  for kS calibration all other variables will be turned on then added back in. should decrease total size of kP. 
  Unlike the objectives of kP kI or kD kS's object is to move consistently as slow as possible to act as an voltage minimum
  for the PID variables.  

  tkS = 1
  No movement 
  tkS = 10
  No movement
  tkS = 50
  No movement
  kS = 100
  No movement 
  kS = 200
  No movement
  kS = 300
  No movement 
  ks = 500
  No movement 
  kS = 1000 
  singular twitch 
  kS = 1100 Numbers are getting pretty high, I guess it makes sense becase it is just straight mini volts and not multipled by anything
  no movement
  kS = 1500
  another twictch
  kS = 2000
  movement slightly fast
  ks = 1900
  movement 
  ks = 1800
  less movement
  ks = 1700
  no movement
  ks = 1750
  no movement
  ks = 1775
  movement but inconsisten
  ks = 1780
  slight twitching?? 
  ks = 1790
  inconsistemtn movent 
  kS = 1800
  nothing
  kS = 1850
  something
  kS = 1900
  nothing? 
  kS = 2000
  good enough time to do kP testing again 

  kP = 1 playing it safe 
  Nevervmind Not using kS, both sides of the Chassis are inconsistent in friction and I already had them pretty much calibrated before it. 
  
  kI = 0.03 two rotations overshoot
  15 rotations full set 
  6 rotations 2 degree overshoot
  1 rotation 1 degree overshoot 

  kI = 0.025
  all 15 rotations 
  all 15 
  4 rotations undershoot 
  5 rotation undershoot
  2 rotation overshoot
  16 rotations 

  PIDs seem good for now, Im going to include a stop fix so incase the PID overshoots or undershoots and cannot move the PID 
  will self destruct causing it automatically go onto the next action. 



  begining calibration of goForward  first test 24 inch move 

  kP = 10
  nothing 
  kP = 50 sidenote fixed the PID reader code and now program displays inches on the side
  nothing 
  kP = 1 
  nothing 
  kP = 100
  nothing
  kP = 1 realaized the ports were negative not the voltage numbers
  Movement in the but constantly accelerating in the wrong direction fixed by reversing encoder values
  very small amounts of movement 
  kP = 3
  4 inches short from target
  kP = 4
  3 inches short from targget
  Day two of calibration. Fixed friction on both sides of the drivetrain. Recalibration of turning PID is neccesary but will be done later 
  Set the error of the PID by 65 degrees or roughly +- .5 inches 
  kP = 5
  3.6 inches short from target 
  kP = 8
  2 inches short from target 
  kP = 10
  1.4 inches from starget 
  kP = 11 
  1.1 inch undershoot 
  kP = 12
  0.9 inch undershoot
  kP = 13 it is above voltage limits but PROS doesn't go above voltage limits of 12V meaning it caps its voltage limits 
  0.9 inch undershoot again? 
  kP = 14
  0.9 undershoot again 
  
  Turns out the math i've been doing makes the upper limit a whole inch and not a half inch
  Reducing error to 32 degrees to 65 so its 0.5 in error instead of 1 in eror 
  kP = 14
  .4 undershoot 

  switching error from 0.5 to 0.25
  kP = 14 
  .2 undershoot

  kP is good for one test, now how about multiple? 

  doing 0 - 12 - 24 - 12 - 0 

  kP = 14
  1 move .6 undershoot
  1 move .5 undershoot 
  1 move .6 undershoot 
  1 move .6 undershoot 
  1 move .6 undershoot 
  kP = 15
  1 move .4 undershoot
  1 move .5 undershoot
  1 move .5 undershoot 
  1 move .5 undershoot
  1 move .5 undershoot
  kP = 16
  1 move .5 undershoot 
  1 move .5 undershoot 
  1 move .5 undershoot 
  1 move .7 undershoot
  1 move .4 undershoot 
  kP = 18 
  Fixed PIDs to actually go inputed distances. Still some issues but will resolve later hopefully
  trials of just 24, there are some complications with movements past that, for now it should be fine 
  Fixed the movement formula so its accurate 
  both movements 
  both movements  doubled movements 
  there is some overshoot sometimes 
  kP = 17 
  2 moves .21 undershoot
  2 moves .31 undershoot
  2 moves .19 undershoot 
  2 moves .3 undershoot 
  2 moves .19 undershoot
  kP = 17.5
  2 moves .26 undershoot 
  1 move  .45 overshoot
  2 moves .25 undershoot
  1 move .45 overshoot
  2 moves .13 undershoot 
  2 moves .34 undershoot 
  1 move .40 overshoot 
  1 move .45 overshoot
  2 moves .20 undershoot 
  2 moves .2 undershoot
  4/10 movements were overshoots and 6/10 were undershoots, safe to assume that kP for now is good and the other variables can suppliemnt the error 
  changing the range of error to 0.25 inches from 0.1 from old calculations. 

  kD = 0.1 
  4 moves
  doubling the amount of moves the robot does.
  8 moves  good 
  halfing the error margin to 0.125 new calculations 
  2 moves 0.28 inch undershoot 
  2 moves 0.21 inch undershoot 
  2 moves 0.19 inch undershoot 

  kD = 0.2
  2 moves .2 inch undershoot 
  2 moves .25 inch undershoot
  2 moves .15 inch undershoot 
  kD isn't fixing anything, maybe slightly increaing kP would work? 
  kP = 17.75
  2 moves .24 undershoot
  2 moves .15 undershoot
  2 moves .16 undershoot 
  kP = 18
  2 moves .19 undershoot 
  2 moves .22 undershoot
  2 moves .16 undershoot 
  maybe kI is the solution? 
  kI = 0.01
  6 moves .21 undershoot 
  2 moves .16 undershoot
  2 moves .22 undershoot 
  kI = 0.02
  8 moves !!! 
  7 moves but weird ending 
  8 moves 0 undershoot or overshoot !!

  Quick turning test using the old method of testing. 
  kP = 135 kI = 0.025 kD = 0.9 for testing counter is off 
  one turn 4 degree overshoot 
  2 turns 4 degree overshoot 
  5 turns 7 degree overshoot 
  kP = 130 (kI anad kD are off)
  1 turn 2 degree overshoot 
  2 turns 2 degree overshoot 
  3 turns 3 degree overshoot 
  kP = 125
  2 turns 2 degree overshoot
  4 turns 2 degree overshoot 
  2 turns 2 degree overshoot 
  kP = 120 
  6 turns all turns 
  6 turns all turns 
  6 turns all turns 
  well kP is good now to turn on the other two varaibles at once 
  kI = 0.025 kD = 0.9 
  6 turns 
  6 turns 
  2 turns overshot 2 degrees 
  2 turns overshoot 1 degree
  6 turns 
  6 turns 
  4 turns 2 degree overshoot 
  kI = 0.02 
  6 turns 
  6 turns 
  2 turns 2 degree overshoot 
  6 turns 
  3 turns 1 degree overshoot 
  1 turn 1 degre overshoot 
  kI = 0.015
  2 turns 2 degree overshoot 
  1 turn 1 degree overshoot 
  2 turns 2 degree overshoot 
  kI = 0.025 kD = 0.8
  6 turns 
  6 turns 
  6 turns 
  Turning and goForward looks good, values are finalized for the comp unless issues arise, counter added back to turn 
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
/*
  intakeMotor.move_velocity(600);
  driveTrain.goForward(24); 
  intakeMotor.move_velocity(0);
  driveTrain.turn(180);
  driveTrain.goForward(24);*/
  

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
