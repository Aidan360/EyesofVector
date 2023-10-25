#include "launcher.hpp"
#include "pros/adi.h"
#include "pros/motors.h"

int catapult::catapultThread() {
    while(true) {
         
        switch (mode = 1) { // Base Catapult Down
            if (pros::c::ext_adi_digital_read(expander_PORT,EXT_cataLimit_PORT) == true) { 
                pros::c::motor_move_velocity(catapultMotor, -120);
            }   
        }
        switch (mode = 2) { // catapult up 
            pros::c::motor_set_brake_mode(catapultMotor, pros::E_MOTOR_BRAKE_COAST);
        }
        switch (mode = 3) { // catapult automatic 
            pros::c::motor_move_velocity(catapultMotor, -200);
        }
        if (reciever = true) {
			pros::c::motor_move_velocity(catapultMotor,-200);
		}  
    }
    return(1);
}