#include "initialize.hpp"
#include "main.h"

namespace vectorR{

class motorClass {
    public: 
    int motorPort;
    double position = 0; // position in odom, 
    double velocity = 0; // velocity in odom,
    double acceleration = 0; // acceleration, 
    double getPosition();
    double getVelocity();
    double getAcceleration();
};
/*class sensorClass {
    double value;
}; */

class moveController{
    private:
    double integral;
    double derivative; 
    motorClass& motor;
    //sensorClass& sensor;
    public: 
    double kP; // PID proportional
    double kI; // PID integral
    double kD; // PID derivative
    double kS; // FF static friction
    double kV; // FF velocity
    double kA; // FF acceleration no god damn clue how I'm doing this EDIT: I will just make a fuction for this 
    moveController(motorClass& m) : motor(m) {} //no clue how to do this 
    double outputPORT;
    double kG = 0; // doesn't matter for any mechanisms we have as of now
    double margin = 0; // error of margin 
    double error = 0;
    double lastError = 0;
    double averageError = 0;
    double output = 0; // In Voltage
    int moveTo(double input);
};
class chassisController{
    public: 
    double kP; // PID proportional
    double kI; // PID integral
    double kD; // PID derivative
    double kS; // FF static friction
    double kV; // FF velocity
    double kA; // FF acceleration no god damn clue how I'm doing this EDIT: I will just make a fuction for this 
    //moveController left;
    //moveController right;
   // void initialize;
};

}