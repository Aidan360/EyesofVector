#include "main.h"
#include "initialize.hpp"
#include <string>
#include <vector> 

class flyWheel { 
    public:
    double kS;
    double kV;
    double kP;
    double kI;
    double kD;
    void spinAt(float velocity); 
    char flyWheelPort;
    bool kill = false;
};

extern flyWheel spinnyThing; 
extern int globalRPM;
extern int pidControl; // used for calibrating Feed forward by turning off PID to let velocity handle higher speeds. 