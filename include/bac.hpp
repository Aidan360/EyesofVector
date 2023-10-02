#include "main.h"
#include "spac.hpp"
#include <string>
#include <vector> 
namespace vectorR{

    class BasicChassis { 
        public:
        std::vector<int> motorPortLeft;
        std::vector<int> motorPortRight;
        float rpm = 360; 
        float wheelSize;
        double velocity;
        float trackLength;
        void goForward(double distance, double velocity);
        void turn(double degrees, double velocity);
        private: 
        double velVol = rpm/127;
    }; 
    class BACGenerator { 
        public:
        std::vector<double> inputs; // Inputs from the Screen Keyboard Function  
        std::vector<double> outPuts; 
        

        void translation(); 
        //void 
         
    }; 
}; 
extern vectorR::BasicChassis driveTrain; 

