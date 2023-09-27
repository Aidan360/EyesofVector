#include "main.h"
#include "initialize.hpp"
#include "bac.hpp" 
#include "pros/adi.hpp"
#include "pros/misc.h"


void autonomous() {
    driveTrain.goForward(48,360);
    driveTrain.turn(720,360);
}