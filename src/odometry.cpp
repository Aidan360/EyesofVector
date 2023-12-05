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
    while (true) { // ONLY INITIALIZE AS THREAD, NEVER FUNCTION
        double motorLeftAvg = 0;
        double motorRightAvg = 0;
        for (int i = 0; i < std::size(motorPortLeft); ++i) {
            motorLeftAvg = motorLeftAvg + pros::c::motor_get_position(motorPortLeft[i]);
            motorRightAvg = motorRightAvg + pros::c::motor_get_position(motorPortRight[i]);
        }
        motorLeftAvg = motorLeftAvg/std::size(motorPortLeft);
        motorRightAvg = motorRightAvg/std::size(motorPortRight);

        heading = lastHeading + (motorLeftAvg - motorRightAvg)/trackLength; 
        double deltaAngle = heading - lastHeading; 
        double distanceOffset = 2*sin(heading/2) * (motorRightAvg/deltaAngle + trackLength/2); // this is the distance travelled, it will be added to "distance" which is purely a PID variable that does not matter whatsoever. 
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
        pros::delay(10);   
    }
}

