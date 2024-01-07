#include "bac.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
void BasicChassis::OdometryThread() { 
    double lastPosition[4]; // x,y then left and right rotations in inches
    double lastHeading; // last Theta value

        for (int i = 0; i < std::size(motorPortLeft); ++i) {
             pros::c::motor_tare_position(motorPortLeft[i]);
             pros::c::motor_tare_position(motorPortRight[i]);
        }
    	pros::Controller master(pros::E_CONTROLLER_MASTER);
          master.clear();
        double motorLeftAvg = 0;
        double motorRightAvg = 0;
         double distanceOffset = 0;
    while (true) { // ONLY INITIALIZE AS THREAD, NEVER FUNCTION

  /*      for (int i = 0; i < std::size(motorPortLeft); ++i) {
            motorLeftAvg = motorLeftAvg + pros::c::motor_get_position(motorPortLeft[i]);
            motorRightAvg = motorRightAvg + pros::c::motor_get_position(motorPortRight[i]);
        } */
        motorLeftAvg = -1* pros::c::motor_get_position(motorPortLeft[1]);
        motorRightAvg = -1* pros::c::motor_get_position(motorPortRight[1]);

        heading = lastHeading + (motorLeftAvg - motorRightAvg)/trackLength; 
        double deltaAngle = heading - lastHeading; 
        distanceOffset = 2*sin(heading/2) * (motorRightAvg/deltaAngle + trackLength/2); // this is the distance travelled, it will be added to "distance" which is purely a PID variable that does not matter whatsoever. 
        distance = distance + distanceOffset;
        position[0] = distanceOffset*sin(heading)+position[0];
        position[1] = distanceOffset*cos(heading)+position[1];

        velocity[0] = position[0] - lastPosition[0]; 
        velocity[1] = position[1] - lastPosition[1];
        velocity[2] = distance - (distance - distanceOffset);

        lastPosition[0] = position[0]; 
        lastPosition[1] = position[1];
        lastPosition[2] = motorLeftAvg;
        lastPosition[3] = motorRightAvg;
        lastHeading = heading;
        for (int i = 0; i < std::size(motorPortLeft); ++i) {
             pros::c::motor_tare_position(motorPortLeft[i]);
             pros::c::motor_tare_position(motorPortRight[i]);
        } 
        pros::delay(10);   
        // DEBUG FUNCTIONS
    
     pros::lcd::print(0, "X: %d\n", int(position[0]));
     pros::lcd::print(1, "Y: %d\n", int(position[1]));
     pros::lcd::print(2, "Head: %d\n", int(heading));
    
    }
}

