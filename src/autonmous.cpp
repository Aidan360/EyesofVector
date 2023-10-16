#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/misc.h"

void autonomous() {
  BasicChassis driveTrain; 
  driveTrain.motorPortLeft.push_back(leftFrontMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftMiddleMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftBackMotor_PORT);
  driveTrain.motorPortRight.push_back(rightFrontMotor_PORT);
  driveTrain.motorPortRight.push_back(rightMiddleMotor_PORT);
  driveTrain.motorPortRight.push_back(rightBackMotor_PORT);
  driveTrain.wheelSize = 3.25;
  driveTrain.trackLength = 12.75; // change when you actually get the robot  */
  driveTrain.tkP = 127;
  driveTrain.tkI = 0.02; 
  driveTrain.tkD = 0.9; 

  driveTrain.fkP = 0.1;
  driveTrain.fkI = 0.1;
  driveTrain.fkD = 0;
  /* 

  90 degree turn tests 1x turn
  tKP = 0.1 nothing
  tKP = 1 nothing
  tKP = 10 Stuttering 
  tKP = 25 more stuttering
  tKP = 50 Seizing 
  tKP = 100 more siezing

  tKP = 200 more siezing
  tKP = 300 more siezing
  tKP = 100 constant overspin, we were just using the wrong direction\
  tKP = 25 constant overspin without stopping or slowing down. Issue is that Doubles cannot equal 0, new error is within 0.5 degrees
  tKP = 25, it got to around 25 degrees than stopped. 
  tKp = 50, it turned around 65 degrees then stopped, almost there 
  tKp = 75 it turned a bit more then stopped. 
  tKp = 100 itsreally close just needs more work. 
  tKp = 125 It was incedibly close to 90 degrees. 90 degrees exactly according to iphone, around 89.5 roughly 
  going into tests of 4 90 degree rotations to properly gauge error 
  tKp = 125 within 2 degrees. which is within error margin, decreasing error margin to 0.1 
  tkP = 125  made past 3 rotations stopped at 4th at 358 according to brain and 359 according to phone
  tKp = 135 1 rotation overshoot fail 
  tkP = 127 2 rotations 1 degree fail
  tKP = 126 4 tests ran 1. 1 rotation 2. 8 rotations somehow. 3 1 rotation 4. 1 rotaiton 
  tKP = 125 tests ran again 1 two rotations, 1 rotation. 
  tKP = 126 has worked the best. onto integral

  adding 8 total rotations to the PID of 90 degrees. 

  tkI = 0.01 3 tests ran: 1: 1 rotation undershoot 2: 2 rotation undershoot 3: 1 rotation undershoot
  tkI = 0.1 1 test. 1 degree overshoot 
  tkI = 0.05 3 rotations 1 degree overshoot
  tkI = 0.025 3 rotations 1 degree undershoot
  tkI = 0.035 2 rotations 1 degree overshoot
  tkI = 0.3 1 rotation 0.4 degree overshoot and 1 degree undershoot 
  tkI = 0.027 1 rotation 1 degree overshoot
  tkI = 0.025 3 rotations 2 degree undershoot
  tkI = 0.026 3 rotations 1 degree overshoot 
                                
  I added the shot blocker to the robot, values may have changed. 
  tkI = 0.0245 1 rotation 1 degree overshoot 
  tKI = 0.025 1 rotation undershot 
 
  old values are no longer working. going to disable tKi until tkP is fixed. 
   tkD needs to be done before tkI meaning all tkI trials are worthless :/
  tkP = 126 2 rotations 1 degree undershot 
  tkP = 130 1 rotation, 1 degreen overshot 
  tkP = 128 5 rotations, the second part of the rotaions is messed up but undershot by 7 degrees. 
  fixed second round of rotations. 
  tkP = 128 2 rotations, .6 degree overshot 
  tkP = 127 4 rotations 1 degree undershot 
  tkP = 127.5 2 rotations .1 degree overshot 
  tkP = 127.45 1 rotation .8 degree undershot 
  tkP = 127.475 1 rotation 0.01 degree undershot
  tkP = 127.48 1 rotation 0.2 degree undershot
  tkp = 127.5 1 rotation .8 degree undershot 
  tkP = 128 3 rotations 1 degree overshot 
   the tkD can handle an overshot and fix it. onto tkD 

  tkD = 0.1 5 rotations but couldn't handle large rotattions maybe an integral thing? 
  going to remove the 270 - 360 to 270 and just do 0 - 90 - 180 - 270 - 180 - 90 

  tkD = 0.1 1 rotation .5 undershoot
  tkD = 0.25 5 rotations 1 degree undershoot
  tkD = 0.5 1 degree undershoot 
  tkD = 0.75 1 degree undershoot 
  tkD = 1 3 rotations .5 degree overshoot 
  tkD = 0.9 4 rotations 1 degree overshoot 
  tkD = 0.8 1 rotation 1 degree undershoot
  tkD = 0.85 3 rotations 2 degree undershoot
  tkD = 0.875 1 degree undershoot
  tkD = 0.9 2 rotations 1 degree undershoot
  tkD = 0.95 overshoot 1 rotation 
  tkD = 0.925 1 rotation undershoot 1 degree 
  tkD = 0.9 1 rotation 2 degrees undershoot ** battery under 20% so power is impacted. charging battery now 
  tkD = 0.9 4 rotations 1 degree overshoot 
  
  This should be fine for now. I think its an issue for the tkP value but we need to move back to integral

  tkI = 0.025 1 rotation .6 degree undershoot
  tkI = 0.05 3 rotations 0.4 degree overshoot
  tkI = 0.04 1 rotation 0.5 degree overshoot
  tkI = 0.03 2 rotations 1 degree overshoot
  tkI = 0.02 1 rotation 0.1 degree overshoot
  tkI = 0.01 4 rotations 0.5 degree overshoot
  tkI = 0.005 2 rotations 0.7 degree overshoot 
  tkI = 0.0025 2 rotations one 360~ complete turn around and then a lot of spinning. beleived code error
  tkI = 0.0025 1 rotation 1 degree overshoot
  tkI = 0.01 4 rotations. 
  
  all results gotten here are the best that could be gotten from 0.1 tolerance with 90 degree turns. 
  Setting tolerances to 0.25 and begin random numbers test. 

  First set: 136 178 79 247 (gotten from googles random number generator 1-360)
  for now on the initial values will be listed then changes will be listed below. 

  tkP = 128 tkI = 0.01 tkD = 0.9 1 rotation 4 degree overshoot, 
  tkP = 125 2 rotations, 7 degree undershoot
  tkP = 126 2 rotations 7 degree undershoot 
  tkI = 0.02 7 degree undershoot 
  
  Remembering now Connor (3249V Vizzion) had a seprarate PID for turns under 25 degrees. 
  In a match scenario we aren't going to be making any turns under 25 degrees so removing all turns within 25 degrees
  should garner results that the current PID can handle. 

  New Second set: 
  74 172 32 211

  tkP = 126 tkI = 0.02 tkD = 0.9 2 rotations 1 degree overshoot
  tkI = 0.01 1 rotation 2 degree underhot 
  tkP = 128 1 rotation 2 degree undershoot 
  tkI = 0.02 1 rotation 2 degree undershoot
  tkP = 130 1 large rotation  10 degree overshoot 
  changed margin to 0.5 
  tkP = 127 Test1  all 4 rotations test 2 all 4 rotations test 3 all 4 rotations test 4 3 rotations undershoot 4 degrees. test 5  all 4 rotations
    */
   //driveTrain.turn(360,360);
	 pros::Motor catapultMotor (catapultMotor_PORT);
	 pros::Motor intakeMotor(intakeMotor_PORT); 
    pros::c::imu_reset_blocking(12);
 // driveTrain.turnM(80, 360);
   //driveTrain.goForward(24);
   driveTrain.turn(74);
   pros::delay(500);
   driveTrain.turn(172);
   pros::delay(500);
   driveTrain.turn(32);
   pros::delay(500);
   driveTrain.turn(211);
   pros::delay(500);
}
