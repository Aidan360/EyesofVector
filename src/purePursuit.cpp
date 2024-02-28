#include "bac.hpp"
#include "initialize.hpp"
#include <limits>
double degRad(double x) {
    return (x * (M_PI/180));
}
double radDeg(double x) {
    return (x* (180/M_PI));
}
bool BasicChassis::trackingCheck(double x1,double x2, double y1, double y2) {
    double x1Offset = x1 - position[0];
    double x2Offset = x2 - position[0];
    double y1Offset = y1 - position[1];
    double y2Offset = y2 - position[1];
    double dx = x2Offset - x1Offset;
    double dy = y2Offset - y1Offset;
    double dr = sqrt(pow(dx,2) + pow(dy,2));
    double D = x1Offset*y2Offset - x2Offset*y1Offset;
    float discriminant = pow(lookAheadRadius,2) * pow(dr,2) - pow(D,2);

    double sol_x1;
    double sol_x2;
    double sol_y1;
    double sol_y2;
    double minX = fmin(x1,x2);
    double maxX = fmax(x1,x2);
    double minY = fmin(y1,y2);
    double maxY = fmax(y1,y2);
    if (discriminant >= 0) {
        sol_x1 = (D * dy + sgn(dy) * dx * sqrt(discriminant)) / pow(dr,2);
        sol_x2 = (D * dy - sgn(dy) * dx * sqrt(discriminant)) / pow(dr,2);
        sol_y1 = (-D * dx + abso(dy) * sqrt(discriminant)) / pow(dr,2);
        sol_y2 = (-D * dx - abso(dy) * sqrt(discriminant)) / pow(dr,2);
        double sol1[2] = {sol_x1 + position[0], sol_y1 + position[1]};
        double sol2[2] = {sol_x2 + position[0], sol_y2 + position[1]};
        if (((minX <= sol1[0]) && (sol1[0] <= maxX) && (minY <= sol1[1]) && (sol1[1] <= maxY)) || ((minX <= sol2[0]) && (sol2[0] <= maxX) && (minY <= sol2[1]) && (sol2[1] <= maxY))) {
            return true;
        }
        else {
            return false;
        }
    }
    
    else {
        return false;
    }



}
/*
bool BasicChassis::trackingCheck(double x1, double x2, double y1, double y2) { // Pure Pursuit runner will be put into a infinite loop in autonomous, when diffrent flags are met things can trigger.
    double sol_x1;
    double sol_x2;
    double sol_y1;
    double sol_y2;
    bool tracking; 


    double x1Offset = x1 - position[0];
    double x2Offset = x2 - position[0];
    double y1Offset = y1 - position[1];
    double y2Offset = y2 - position[1];
        
    double dx = x2Offset - x1Offset;
    double dy = y2Offset - y1Offset;
    double dr = sqrt(pow(dx,2) + pow(dy,2));
    double D = x1Offset*y2Offset - x2Offset*y1Offset;
    float discriminant = pow(lookAheadRadius,2) * pow(dr,2) - pow(D,2);

    double minX = fmin(x1,x2);
    double maxX = fmax(x1,x2);
    double minY = fmin(y1,y2);
    double maxY = fmax(y1,y2);
    if (discriminant >= 0) { 
        sol_x1 = (D * dy + sgn(dy) * dx * sqrt(discriminant)) / pow(dr,2);
        sol_x2 = (D * dy - sgn(dy) * dx * sqrt(discriminant)) / pow(dr,2);
        sol_y1 = (-D * dx + abso(dy) * sqrt(discriminant)) / pow(dr,2);
        sol_y2 = (-D * dx - abso(dy) * sqrt(discriminant)) / pow(dr,2);

        if(!(x1Offset < sol_x1 < x2Offset) && !(y1Offset < sol_y1 < y2Offset)) { 
            discriminant = 0;
        }
        else if(!(x1Offset < sol_x2 < x2Offset) && !(y1Offset < sol_y2 < y2Offset)) {
            discriminant = 0; 
        }   
        else {
            return true;
        }         
        } // !(x1Offset < sol_x2 < x2Offset)   && !(y1Offset < sol_y2 < y2Offset)
        if (discriminant == 0) {
            sol_x1 = (D * dy + sgn(dy) * dx * sqrt(discriminant)) / pow(dr,2);
            sol_x2 = (D * dy - sgn(dy) * dx * sqrt(discriminant)) / pow(dr,2);
            sol_y1 = (-D * dx + abso(dy) * sqrt(discriminant)) / pow(dr,2);
            sol_y2 = (-D * dx - abso(dy) * sqrt(discriminant)) / pow(dr,2);
            if(!(x1Offset < sol_x1 < x2Offset) && !(y1Offset < sol_y1 < y2Offset) && !(x1Offset < sol_x2 < x2Offset) && !(y1Offset < sol_y2 < y2Offset)) { 
                discriminant = -1;
            }
            else {
                return false; 
            }
        }
        if (discriminant <= 0) {
            return false;
        }
        else {
            return false;
        }
        
} */
    void BasicChassis::curveInterpolation() {
        int i = 0;
        int j = 1;
        float t = injectionMultipler;
        while(std::size(pursuitPoints) > i) {
            if (std::size(pursuitPoints)-i-2 >= 0) {
                injectionPoints.push_back({pursuitPoints[i][0],pursuitPoints[i][1],pursuitPoints[i][2]}); 
                
                while (!(injectionMultipler == j)) {
                float x1 = pursuitPoints[i][0];
                float y1 = pursuitPoints[i][1];
                float x2 = pursuitPoints[i+1][0];
                float y2 = pursuitPoints[i+1][1];
                float x3 = pursuitPoints[i+2][0];
                float y3 = pursuitPoints[i+2][1];
                t = 1*(1.0/injectionMultipler)*j;
                float xO = pow(1-t,2)*x1+2*(1-t)*t*x2+pow(t,2)*x3;
                float yO = pow(1-t,2)*y1+2*(1-t)*t*y2+pow(t,2)*y3;
                injectionPoints.push_back({xO,yO,pursuitPoints[i][2]});
                j++;
                }
            j = 1;
            i = i+2;    
            }      
        }
    }
    void BasicChassis::purePursuit() {
        double lastPosition[4]; // x,y then left and right rotations in inches
        double lastHeading; // last Theta value
        double gearRatio = 0.6;
        double motorLeftAvg;
        double motorRightAvg;
        double deltaLeft;
        double deltaRight;
        double distLeft;
        double distRight;
        double deltaAngle = heading;
        float distanceOffset;    
        double orientationAvg = 0;
        position[0] = pursuitPoints[0][0];
        position[1] = pursuitPoints[0][1];
        pros::c::imu_set_heading(IMU_PORT, position[2]); // 180 for first auton, 225 for second one.  135 for skills
        pros::c::motor_tare_position(motorPortLeft[0]);
        pros::c::motor_tare_position(motorPortRight[0]);
        pros::c::motor_tare_position(motorPortLeft[1]);
        pros::c::motor_tare_position(motorPortRight[1]);
        pros::c::motor_tare_position(motorPortLeft[2]);
        pros::c::motor_tare_position(motorPortRight[2]);
     //   distToNextPoint =  sqrt(pow(injectionPoints[lastPointIndex + 1][0] - position[0],2) + pow(injectionPoints[lastPointIndex + 1][1] - position[0],2));



        double linearError; 
        double linearLastError; 
        double linearIntegral;
        double linearDerivative;
        float linearOutput;
        int linearIntError = sgn(linearError);

        double rotationalError;
        double rotationalLastError;
        double rotationalIntegral;
        double rotationalDerivative;
        float rotationalOutput;
        int rotationalIntError = sgn(rotationalError);
        lastPointIndex = 0;
        curveInterpolation(); 
        pros::delay(1000);
        double cartToPolarR;
        double cartToPolarθ;
        while (true) {
        /* Odometry */
        motorLeftAvg =  (pros::c::motor_get_position(motorPortLeft[1])+pros::c::motor_get_position(motorPortLeft[0]))/2*gearRatio;
        motorRightAvg =  (pros::c::motor_get_position(motorPortRight[1])+pros::c::motor_get_position(motorPortRight[0]))/2*gearRatio;
        deltaLeft = (motorLeftAvg - lastPosition[2]);
        deltaRight = (motorRightAvg - lastPosition[3]);
        distLeft = degRad(deltaLeft) * (wheelSize/2);
        distRight = degRad(deltaRight) * (wheelSize/2);  

        heading = heading + ((distLeft - distRight)/trackLength)*-1; 
       //heading = int(pros::c::imu_get_heading(IMU_PORT)*10000000)*0.0000001;
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
        position[1] = cartToPolarR*sin(cartToPolarθ-orientationAvg)*-1+position[1];

        
        lastPosition[0] = position[0]; 
        lastPosition[1] = position[1];
        lastPosition[2] = motorLeftAvg;
        lastPosition[3] = motorRightAvg;
        lastHeading = heading;
        position[2] = pros::c::imu_get_heading(IMU_PORT); 
        /*motorLeftAvg =  pros::c::motor_get_position(motorPortLeft[1])*gearRatio;
        motorRightAvg = pros::c::motor_get_position(motorPortRight[1])*gearRatio;
        deltaLeft = (motorLeftAvg - lastPosition[2]);
        deltaRight = (motorRightAvg - lastPosition[3]);
        distLeft = degRad(deltaLeft) * (wheelSize/2);
        distRight = degRad(deltaRight) * (wheelSize/2); 
        
        heading = degRad(pros::c::imu_get_heading(IMU_PORT));
        //heading = heading + ((distLeft - distRight)/trackLength);
        deltaAngle = heading-lastHeading;
        if(deltaAngle > 0.01) {
            if (distRight > 0.05) { 
            distanceOffset = distRight;
            }
            else {
                distanceOffset = distLeft;
            }
        }
        else {

            if (distRight > 0.05) { 
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
      //  position[1] = (heading);
      //  position[0] = distanceOffset*100;
       position[1] = cartToPolarR*sin(cartToPolarθ-orientationAvg)+position[1];

        position[2] = (pros::c::imu_get_heading(IMU_PORT));
        lastPosition[0] = position[0]; 
        lastPosition[1] = position[1];
        lastPosition[2] = motorLeftAvg;
        lastPosition[3] = motorRightAvg;
        lastHeading = heading;
        */
        /*Pure Pursuit*/
       
        distToNextPoint = sqrt(pow(injectionPoints[lastPointIndex + 1][0] - position[0],2) + pow(injectionPoints[lastPointIndex + 1][1] - position[0],2));
        distToNextPoint = sqrt(pow(injectionPoints[lastPointIndex + 1][0] - position[0],2) + pow(injectionPoints[lastPointIndex + 1][1] - position[1],2));
        float distToNextPursuitPoint = sqrt(pow(pursuitPoints[lastPursuitIndex + 1][0] - position[0],2) + pow(pursuitPoints[lastPursuitIndex + 1][1] - position[0],2));

        if (distToNextPoint <= lookAheadRadius) {
            lastPointIndex = lastPointIndex + 1;
        }
        if (distToNextPursuitPoint <= lookAheadRadius) {
            lastPursuitIndex = lastPursuitIndex + 1;
        }
        float targetAngle =  radDeg(atan2(injectionPoints[lastPointIndex + 1][1] - position[1],injectionPoints[lastPointIndex + 1][0] - position[0]));
        float minAngle = abso(targetAngle) - position[2];
        if (injectionPoints[lastPointIndex + 1][2] == -1) {
            minAngle = abso(targetAngle) - position[2] + 180;
        }
        if (minAngle > 180 || minAngle < -180) {
                minAngle = -1 * sgn(minAngle) * 360-abso(minAngle);
        }
        if (trackingCheck(injectionPoints[lastPointIndex][0], injectionPoints[lastPointIndex + 1][0], injectionPoints[lastPointIndex][1], injectionPoints[lastPointIndex + 1][1]) == true) {
                linearError = distToNextPoint;
                rotationalError = 0;
        }
        else {
                linearError = distToNextPoint;
                rotationalError = minAngle;
        }
        if ((std::size(injectionPoints)-1) <= lastPointIndex) {
                break;
        }  
        /*PIDs*/

        linearIntegral = linearIntegral + linearError;
        linearDerivative = linearError - linearLastError;
        linearOutput = (fkP*linearError + fkI*linearIntegral + fkD*linearDerivative) * injectionPoints[lastPointIndex+1][2];

        rotationalIntegral = rotationalIntegral + rotationalError;
        rotationalDerivative = rotationalError - rotationalLastError;
        rotationalOutput = (tkP*rotationalError + tkI*rotationalIntegral + tkD*linearDerivative) * injectionPoints[lastPointIndex+1][2];
        
   /*     if (rotationalError == 0) {
            pros::c::motor_move_voltage(motorPortLeft[0],linearOutput);
            pros::c::motor_move_voltage(motorPortLeft[1],linearOutput);
            pros::c::motor_move_voltage(motorPortLeft[2],linearOutput);
            pros::c::motor_move_voltage(motorPortRight[0],linearOutput);
            pros::c::motor_move_voltage(motorPortRight[1],linearOutput);
            pros::c::motor_move_voltage(motorPortRight[2],linearOutput); 
        } 
        else { */
            pros::c::motor_move_voltage(motorPortLeft[0],linearOutput - rotationalOutput);
            pros::c::motor_move_voltage(motorPortLeft[1],linearOutput - rotationalOutput);
            pros::c::motor_move_voltage(motorPortLeft[2],linearOutput - rotationalOutput);
            pros::c::motor_move_voltage(motorPortRight[0],linearOutput + rotationalOutput);
            pros::c::motor_move_voltage(motorPortRight[1],linearOutput + rotationalOutput);
            pros::c::motor_move_voltage(motorPortRight[2],linearOutput + rotationalOutput); 
 
        
        linearLastError = linearError;
        rotationalLastError = rotationalError;

        if (sgn(linearError) != linearIntError) {
            linearIntegral = 0;
            linearIntError = sgn(linearIntegral);
        }
        if (sgn(rotationalError) != rotationalIntError) {
            rotationalIntegral = 0;
            rotationalIntError = sgn(rotationalIntegral);
        }
        pros::lcd::print(0, "Lin: %d\n",int(linearError));
        pros::lcd::print(1, "Rot: %d\n",int(rotationalError));
        pros::lcd::print(2,"LPP: %d\n", int(lastPointIndex));
        pros::lcd::print(3, "X: %f", position[0]);
        pros::lcd::print(4,"Y: %f", position[1]);
        pros::lcd::print(5,"H: %d\n", int(radDeg(heading)));
        
        
       // pros::lcd::print(0, "turn %d\n", int(pros::c::imu_get_heading(IMU_PORT)));
        pros::delay(20);
        }
        pros::c::motor_move_voltage(motorPortLeft[0],0);
        pros::c::motor_move_voltage(motorPortLeft[1],0);
        pros::c::motor_move_voltage(motorPortLeft[2],0);
        pros::c::motor_move_voltage(motorPortRight[0],0);
        pros::c::motor_move_voltage(motorPortRight[1],0);
        pros::c::motor_move_voltage(motorPortRight[2],0);    


    }
    