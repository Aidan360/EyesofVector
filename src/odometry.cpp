#include "bac.hpp"
#include "pros/imu.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include <cmath>
#include "initialize.hpp"
double degRad(double x) {
    return (x * (M_PI/180));
}
double radDeg(double x) {
    return (x* (180/M_PI));
}
void BasicChassis::OdometryThread() { 
    double lastPosition[4]; // x,y then left and right rotations in inches
    double lastHeading; // last Theta value

        for (int i = 0; i < std::size(motorPortLeft); ++i) {
             pros::c::motor_tare_position(motorPortLeft[i]);
             pros::c::motor_tare_position(motorPortRight[i]);
        }
        //pros::c::imu_tare(11);
        //pros::delay(500);
    	pros::Controller master(pros::E_CONTROLLER_MASTER);
          master.clear();
        double motorLeftAvg = 0;
        double motorRightAvg = 0;
        double distanceOffset = 0;
        double deltaLeft = 0;
        double deltaRight = 0;
        double distLeft = 0;
        double distRight = 0;
        double newHeading = 0;
        double orientationAvg = 0;
        double cartToPolarR = 0;  
        double cartToPolarθ = 0;
        double deltaAngle = 0;
        double gearRatio = 0.6;
    while (true) { // ONLY INITIALIZE AS THREAD, NEVER FUNCTION

  /*      for (int i = 0; i < std::size(motorPortLeft); ++i) {
            motorLeftAvg = motorLeftAvg + pros::c::motor_get_position(motorPortLeft[i]);
            motorRightAvg = motorRightAvg + pros::c::motor_get_position(motorPortRight[i]);
        } */
        motorLeftAvg = -1* pros::c::motor_get_position(motorPortLeft[1])*gearRatio;
        motorRightAvg = -1* pros::c::motor_get_position(motorPortRight[1])*gearRatio;
        deltaLeft = (motorLeftAvg - lastPosition[2]);
        deltaRight = (motorRightAvg - lastPosition[3]);
        distLeft = degRad(deltaLeft) * (wheelSize/2);
        distRight = degRad(deltaRight) * (wheelSize/2);  

        heading = heading + ((distLeft - distRight)/trackLength); 
      //  heading = pros::c::imu_get_heading(11);
        deltaAngle = heading - lastHeading;
        if(deltaAngle < 0.1) {
            if (distRight == 0) { 
            distanceOffset = distRight;
            }
            else {
                distanceOffset = distLeft;
            }
        }
        else {

            if (distRight == 0) { 
                distanceOffset = 2*sin(heading/2) * (distRight/deltaAngle + (trackLength/2)); // this is the distance travelled, it will be added to "distance" which is purely a PID variable that does not matter whatsoever. 
            }
            else {
                distanceOffset = 2*sin(heading/2) * (distLeft/deltaAngle + (trackLength/2)); // this is the distance travelled, it will be added to "distance" which is purely a PID variable that does not matter whatsoever. 
            }    
        }
        orientationAvg = lastHeading + deltaAngle/2;
        cartToPolarR = distanceOffset;  
        cartToPolarθ = 0; 
        position[0] = cartToPolarR*cos(cartToPolarθ-orientationAvg)+position[0];
        position[1] = cartToPolarR*sin(cartToPolarθ-orientationAvg)+position[1];

        
        lastPosition[0] = position[0]; 
        lastPosition[1] = position[1];
        lastPosition[2] = motorLeftAvg;
        lastPosition[3] = motorRightAvg;
        lastHeading = heading;
 
        pros::delay(10);   
        // DEBUG FUNCTIONS
    
     pros::lcd::print(0, "X: %f", position[0]);
     pros::lcd::print(1, "Y: %f", position[1]);
     pros::lcd::print(2, "Head: %d\n", int(radDeg(heading)));
 //    pros::lcd::print(3,"kms: %f", distanceOffset);
    pros::lcd::print(4,"z: %f", position[0]);
     pros::lcd::print(5,"j: %f", position[1]);
    
    }
}

