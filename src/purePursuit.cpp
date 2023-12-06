#include "bac.hpp"
#include "initialize.hpp"
#include <limits>
bool BasicChassis::trackingCheck(double x1, double x2, double y1, double y2) { // Pure Pursuit runner will be put into a infinite loop in autonomous, when diffrent flags are met things can trigger.
    int currentPoints[2] = {0,1};
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
        
    // look ahead radius^2 * distance formula of both points^2 * (x1y2 - x2y1)^2 if positive two intersections?
    // reminder to install limits of the two points
}


/* Velocity Dampener */
/* 
    for every x degree off x RPM increases and decreases on both sides of the chassis to maintain speed while turning. 

    for initial testing 1 degree per one rpm (max 360 so 360 degree turn will be pos 360 and -360)

*/

void BasicChassis::leftSide(double velocity) {
    double lastError = 0;
    double error = velocity * 1.666666667 / 3 - pros::c::motor_get_actual_velocity(motorPortLeft[0]); 
    double integral = 0;
    double derivative = 0; 
    int intError = sgn(error);

    while (true) {

        error = velocity * 1.666666667 / 3 - pros::c::motor_get_actual_velocity(motorPortLeft[0]); 
        integral = integral + error;
        derivative = error - lastError;
        double output = lkP*error + lkI*integral + lkD*derivative + sgn(error)*lkS + lkV* (pros::c::motor_get_actual_velocity(motorPortLeft[0]) * 1.666666667 / 3 ); 
        for (int i = 0; i < std::size(motorPortLeft); ++i) {
            pros::c::motor_move_voltage(motorPortLeft[i],output * -1);
        }
        if (sgn(error) != intError) {
            integral = 0;
            intError = sgn(error);
        }
        pros::delay(10);

    }
}
void BasicChassis::rightSide(double velocity) {
    double lastError = 0;
    double error = velocity * 1.666666667 / 3 - pros::c::motor_get_actual_velocity(motorPortRight[0]); 
    double integral = 0;
    double derivative = 0; 
    int intError = sgn(error);
    while (true) {

        error = velocity * 1.666666667 / 3 - pros::c::motor_get_actual_velocity(motorPortRight[0]); 
        integral = integral + error;
        derivative = error - lastError;
        double output = rkP*error + rkI*integral + rkD*derivative + sgn(error)*rkS + rkV* (pros::c::motor_get_actual_velocity(motorPortRight[0]) * 1.666666667 / 3 ); 
        for (int i = 0; i < std::size(motorPortRight); ++i) {
            pros::c::motor_move_voltage(motorPortRight[i],output * -1);
        }
        if (sgn(error) != intError) {
            integral = 0;
            intError = sgn(error);
        }
        pros::delay(10);

    }
}


