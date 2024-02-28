#include "main.h"
#include "spac.hpp"
#include <string>
#include <vector> 


    class BasicChassis { 
        public:
        std::vector<int> motorPortLeft;
        std::vector<int> motorPortRight;
        std::vector<std::array<float,3>> pursuitPoints;
        std::vector<std::array<float,3>> injectionPoints;
        int lastPursuitIndex;
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
        double ckP;
        double ckI;
        double ckD;
        double ckS;
        void purePursuit();
        int lastPointIndex = 0;
        float heading;
        float position[3]; // x,y,heading
        void OdometryThread();
        bool fail; // failsafe for calibrator 
        char IMUPort; 
        char top;
        char bottom;
        void goForward(double inch);
        void turn(double degree);
        void goForwardM(double distance, double velocity);
        void goForwardO(double distance, double velocity);
        double distance;
        bool trackingCheck(double x1, double x2, double y1, double y2);
        float lookAheadRadius;
        float distToNextPoint;
        void turnM(double degrees, double velocity);
        void turnO(double degrees, double velocity);

        int calibrator(float inputP, float inputI, float inputD, float inputS,bool type); 
        double runner(bool type);
        int injectionMultipler;
        void curveInterpolation();        
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
