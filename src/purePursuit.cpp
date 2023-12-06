#include "bac.hpp"
#include "initialize.hpp"
#include <limits>
void BasicChassis::PurePursuitThread() { // Pure Pursuit runner will be put into a infinite loop in autonomous, when diffrent flags are met things can trigger.
    int currentPoints[2] = {0,1};
    double sol_x1;
    double sol_x2;
    double sol_y1;
    double sol_y2; 
    while (true) { 
        double x1 = pursuitPoints[currentPoints[0]][0];
        double x2 = pursuitPoints[currentPoints[1]][0];
        double y1 = pursuitPoints[currentPoints[0]][1];
        double y2 = pursuitPoints[currentPoints[1]][1];
        
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
                
            }         
        } // !(x1Offset < sol_x2 < x2Offset)   && !(y1Offset < sol_y2 < y2Offset)
        if (discriminant == 0) {
            if(!(x1Offset < sol_x1 < x2Offset) && !(y1Offset < sol_y1 < y2Offset)) { 
                discriminant = 0;
            }
            else if(!(x1Offset < sol_x2 < x2Offset) && !(y1Offset < sol_y2 < y2Offset)) {
                discriminant = 0; 
            }  
        }
        if (discriminant <= 0) {

        }
    }
    // look ahead radius^2 * distance formula of both points^2 * (x1y2 - x2y1)^2 if positive two intersections?
    // reminder to install limits of the two points
}