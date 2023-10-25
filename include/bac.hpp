#include "main.h"
#include "spac.hpp"
#include <string>
#include <vector> 


    class BasicChassis { 
        public:
        std::vector<int> motorPortLeft;
        std::vector<int> motorPortRight;
        float rpm = 360; 
        float wheelSize;
        double velocity;
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
        char IMUPort; 
        char top;
        char bottom;
;
        void goForward(double inch);
        void turn(double degree);
        void goForwardM(double distance, double velocity);
        void turnM(double degrees, double velocity);
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

