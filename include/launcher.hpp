#include "initialize.hpp"

class catapult { 
    public:
    int mode; 
    int catapultMotor;
    char limitSwitch;
    char extenderPort;
    bool reciever;
    int catapultThread();
};