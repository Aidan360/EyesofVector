#include "main.h"
#include "spac.hpp"
#include <string>
#include <vector> 


    class BasicChassis { 
        public:
        std::vector<int> motorPortLeft;
        std::vector<int> motorPortRight;
        
        std::vector<std::array<float,3>> pursuitPoints; // x and y positions with velcoity being the values
        int segments = std::size(pursuitPoints)-1; 
        
        float rpm = 360; 
        float wheelSize;
        float lookAheadRadius;   
        float trackLength;
        public: 
        double tkS;
        double tkP;
        double tkI;
        double tkD;
        double fkS;
        double fkP;
        double fkI;
        double fkD;
        double ckP;
        double ckI;
        double ckD;
        double ckS; 
        // New PID variables made for Pure pursuit and Independent Chassis Control. The t variables can still be used for other purposes l is for left side r is for right side
        // there shouldn't be much difference in l and r but if there is the PIDs should correct that. 
        double lkS; 
        double lkV; 
        double lkP; 
        double lkI; 
        double lkD; 
        double rkS;
        double rkV; 
        double rkP; 
        double rkI; 
        double rkD; 
        double vC; // correctional velocity variable 
        int lastPointIndex;
        void leftSide(double velocity);  
            double leftVelocity;
        void rightSide(double velocity); 
            double rightVelocity;
        bool fail; // failsafe for calibrator 
        char IMUPort; 
        char top; // uhhh don't use
        char bottom; // uhhh don't use
        double position[2]; // x,y
        double velocity[3]; // x,y and current 
        double heading; // radians
        double distance; // Relative to PID functions but 
        void goForward(double inch); // currently broken :/
        void turn(double degree); 
        void goForwardM(double distance, double velocity);
        void turnM(double degrees, double velocity);
        int calibrator(float inputP, float inputI, float inputD, float inputS,bool type); 
        void OdometryThread();
        void PurePursuitThread();
        int PursuitKill = 0;
        bool trackingCheck(double x1, double x2, double y1, double y2);
        int totalPairs; // Total number of point pairs
        class pointPair { // object of point pairs and the decider for when to switch to the next point in the pure pursuit. 
            int PairNum;
            double pointA[2];
            double pointB[2];
            double distFromCenter;
        };
        double runner(bool type);
        
        private: 
        double velVol = 600/rpm;
        double error;
        double integral; 
        double derivative; 
    }; 
    class cataPult {};
    class BACGenerator { 
        public:
        std::vector<double> inputs; // Inputs from the Screen Keyboard Function  
        std::vector<double> outPuts; 
        

        void translation(); 
        //void 
         
    }; 

extern BasicChassis driveTrain; 
