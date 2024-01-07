#include "bac.hpp"
#include "initialize.hpp"
#include <limits>
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
        
}

void BasicChassis::leftSide(double velocity) {
    double lastError = 0;
    double error = 0; 
    double integral = 0;
    double derivative = 0; 
    int intError = sgn(error);

    while (true) {

        error = (velocity) - pros::c::motor_get_actual_velocity(motorPortLeft[0]); 
        integral = integral + error;
        derivative = error - lastError;
        double output = (lkP*error + lkI*integral + lkD*derivative + sgn(error)*lkS + lkV* (pros::c::motor_get_actual_velocity(motorPortLeft[0]) * 1.666666667 / 3 )); 
            pros::c::motor_move_voltage(motorPortLeft[0],output *-1 );
            pros::c::motor_move_voltage(motorPortLeft[1],output *-1 );
            pros::c::motor_move_voltage(motorPortLeft[2],output *-1);
        if (sgn(error) != intError) {
            integral = 0;
            intError = sgn(error);
        }
        velocity = leftVelocity;
        pros::delay(10);
        if(PursuitKill == 1) {
            break;
        }

    }
}
void BasicChassis::rightSide(double velocity) {
    double lastError = 0;
    double error = velocity - pros::c::motor_get_actual_velocity(motorPortRight[0]); 
    double integral = 0;
    double derivative = 0; 
    int intError = sgn(error);
    while (true) {

        error = (velocity) - pros::c::motor_get_actual_velocity(motorPortRight[0]); 
        integral = integral + error;
        derivative = error - lastError;
        double output = (rkP*error + rkI*integral + rkD*derivative + sgn(error)*rkS + rkV* (pros::c::motor_get_actual_velocity(motorPortRight[0]) * 1.666666667 / 3 )); 
            pros::c::motor_move_voltage(motorPortRight[0],output*-1);
            pros::c::motor_move_voltage(motorPortRight[1],output*-1);
            pros::c::motor_move_voltage(motorPortRight[2],output*-1);
        if (sgn(error) != intError) {
            integral = 0;
            intError = sgn(error);
        }
        velocity = rightVelocity;
        pros::delay(10);
        if(PursuitKill == 1) {
            break;
        }
    }
    
}
void BasicChassis::pursuitChassisControler() {
    double LlastError = 0;
    double Lerror = leftVelocity - pros::c::motor_get_actual_velocity(motorPortRight[0]); 
    double Lintegral = 0;
    double Lderivative = 0; 
    int LintError = sgn(error);
    double RlastError = 0;
    double Rerror = rightVelocity - pros::c::motor_get_actual_velocity(motorPortRight[0]); 
    double Rintegral = 0;
    double Rderivative = 0; 
    int RintError = sgn(error);
     while (true) {

        Rerror = (rightVelocity) - pros::c::motor_get_actual_velocity(motorPortRight[0]); 
        Rintegral = Rintegral + error;
        Rderivative = Rerror - RlastError;
        double Routput = (rkP*error + rkI*Rintegral + rkD*Rderivative + sgn(Rerror)*rkS + rkV* (pros::c::motor_get_actual_velocity(motorPortRight[0]) * 1.666666667 / 3 )); 
            pros::c::motor_move_voltage(motorPortRight[0],Routput*-1);
            pros::c::motor_move_voltage(motorPortRight[1],Routput*-1);
            pros::c::motor_move_voltage(motorPortRight[2],Routput*-1);
        if (sgn(error) != RintError) {
            Rintegral = 0;
            RintError = sgn(error);
        }
        pros::delay(10);
        if(PursuitKill == 1) {
            break;
        }
    }
}

void BasicChassis::PurePursuitThread() { // pure pursuit should work :D
    lastPointIndex = 0;
    distToNextPoint =  sqrt(pow(pursuitPoints[lastPointIndex + 1][0] - position[0],2) + pow(pursuitPoints[lastPointIndex + 1][1] - position[0],2));
;
    while (true){
    //double correctionVelocity = vC* atan2(pursuitPoints[lastPointIndex + 1][1] - position[1],pursuitPoints[lastPointIndex + 1][0] - position[0]); // correctional velocity 
    distToNextPoint = sqrt(pow(pursuitPoints[lastPointIndex + 1][0] - position[0],2) + pow(pursuitPoints[lastPointIndex + 1][1] - position[1],2));

    if (distToNextPoint <= lookAheadRadius) {
        lastPointIndex++;
    } // moves the path onto the next point

    if (std::size(pursuitPoints) <= lastPointIndex) {
        PursuitKill = 0;
    }
    double correctionVelocity = 0;
    if (trackingCheck(pursuitPoints[lastPointIndex][0], pursuitPoints[lastPointIndex + 1][0], pursuitPoints[lastPointIndex][1], pursuitPoints[lastPointIndex + 1][1])) {
        leftVelocity = pursuitPoints[lastPointIndex + 1][2] + pC*correctionVelocity; // pC = passive correction
        rightVelocity = pursuitPoints[lastPointIndex + 1][2] - pC*correctionVelocity;
    }
    else { 
        leftVelocity = aC *pursuitPoints[lastPointIndex + 1][2] + correctionVelocity; // aC = active correction.
        rightVelocity = aC * pursuitPoints[lastPointIndex + 1][2] - correctionVelocity;
    }
    
    distToNextPoint = sqrt(pow(pursuitPoints[lastPointIndex + 1][0] - position[0],2) + pow(pursuitPoints[lastPointIndex + 1][1] - position[0],2));
 // moves the path onto the next point
    }
    if (PursuitKill == 1) {
        leftVelocity = 0;
        rightVelocity = 0;
    }
} 