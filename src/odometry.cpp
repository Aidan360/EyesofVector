#include "bac.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include <cmath>
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
    	pros::Controller master(pros::E_CONTROLLER_MASTER);
          master.clear();
        float motorLeftAvg = 0;
        float motorRightAvg = 0;
        float distanceOffset = 0;
        float deltaLeft = 0;
        float deltaRight = 0;
        float distLeft = 0;
        float distRight = 0;
        float newHeading = 0;
        float orientationAvg = 0;
        double cartToPolarR = 0;  
        double cartToPolarθ = 0;
    while (true) { // ONLY INITIALIZE AS THREAD, NEVER FUNCTION

  /*      for (int i = 0; i < std::size(motorPortLeft); ++i) {
            motorLeftAvg = motorLeftAvg + pros::c::motor_get_position(motorPortLeft[i]);
            motorRightAvg = motorRightAvg + pros::c::motor_get_position(motorPortRight[i]);
        } */
        motorLeftAvg = -1* pros::c::motor_get_position(motorPortLeft[1]);
        motorRightAvg = -1* pros::c::motor_get_position(motorPortRight[1]);
        deltaLeft = (motorLeftAvg - lastPosition[2]);
        deltaRight = (motorRightAvg - lastPosition[3]);
        distLeft = degRad(deltaLeft) * (wheelSize/2);
        distRight = degRad(deltaRight) * (wheelSize/2);  

        heading = heading + ((distLeft - distRight)/trackLength); 
        float deltaAngle = heading - lastHeading;
        if(deltaAngle < 0.01) {
            if (distRight == 0) { 
            distanceOffset = distRight;
            }
            else {
                distanceOffset = distLeft;
            }
        }
        else {

            if (distRight == 0) { 
            distanceOffset = distanceOffset = 2*sin(heading/2) * (distRight/deltaAngle + (trackLength/2)); // this is the distance travelled, it will be added to "distance" which is purely a PID variable that does not matter whatsoever. 

;
            }
            else {
                distanceOffset = distanceOffset = 2*sin(heading/2) * (distLeft/deltaAngle + (trackLength/2)); // this is the distance travelled, it will be added to "distance" which is purely a PID variable that does not matter whatsoever. 

;
            }    
                }
        orientationAvg = lastHeading + deltaAngle/2;
        cartToPolarR = sqrt(distanceOffset);  
        cartToPolarθ = atan(distanceOffset); 
        position[0] = cartToPolarR*cos(cartToPolarθ-orientationAvg)+position[0];
        position[1] = cartToPolarR*sin(cartToPolarθ-orientationAvg)+position[1];

        
        lastPosition[0] = position[0]; 
        lastPosition[1] = position[1];
        lastPosition[2] = motorLeftAvg;
        lastPosition[3] = motorRightAvg;
        lastHeading = heading;
 
        pros::delay(10);   
        // DEBUG FUNCTIONS
    
     pros::lcd::print(0, "X: %f",  cartToPolarR*cos(cartToPolarθ-orientationAvg)+position[0]);
     pros::lcd::print(1, "Y: %f",  cartToPolarR*sin(cartToPolarθ-orientationAvg)+position[1]);
     pros::lcd::print(2, "Head: %d\n", int(radDeg(heading)));
     pros::lcd::print(3,"kms: %f", distanceOffset);
    
    }
}

