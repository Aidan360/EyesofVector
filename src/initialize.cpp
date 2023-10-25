#include "main.h"
#include "initialize.hpp"
#include "pros/adi.hpp"
#include "bac.hpp" 
void initialize() {
	// initializers
    pros::lcd::initialize();
    pros::Motor leftFrontMotor_initializer (leftFrontMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor leftMiddleMotor_initializer (leftMiddleMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);  
    pros::Motor leftBackMotor_initializer (leftBackMotor_PORT, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightFrontMotor_initializer (rightFrontMotor_PORT, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightMiddleMotor_initializer (rightMiddleMotor_PORT, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); 
    pros::Motor rightBackMotor_initializer (rightBackMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor catapult_initializer (catapultMotor_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor intake_initializer (intakeMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::ADIEncoder encoderL_initializer (encoderLeftTop_PORT,encoderLeftBottom_PORT, false);
    pros::ADIEncoder encoderR_initializer (encoderRightTop_PORT,encoderRightBottom_PORT, false);
    pros::ADIEncoder encoderB_initializer (encoderBackTop_PORT,encoderBackBottom_PORT, false);
 //   pros::ADIDigitalOut climbingPTO_initializer (climbingPTO_PORT);
    pros::ADIDigitalOut flapLeft_initializer ({{expander_PORT,EXT_flapLeft_PORT}});
    pros::ADIDigitalOut flapRight_initializer ({{expander_PORT,EXT_flapRight_PORT}});
    pros::ADIDigitalIn cataLimit_initializer ({{expander_PORT,EXT_cataLimit_PORT}});
    pros::Imu intertia_initializer (IMU_PORT);

    
    // declarations
    pros::ADIEncoder encoderL (encoderLeftTop_PORT,encoderLeftBottom_PORT);
    pros::ADIEncoder encoderR (encoderRightTop_PORT,encoderRightBottom_PORT);
    pros::ADIEncoder encoderB (encoderBackTop_PORT,encoderBackBottom_PORT);
    pros::Motor leftFrontMotor (leftFrontMotor_PORT);
    pros::Motor leftMiddleMotor (leftMiddleMotor_PORT);
    pros::Motor leftBackMotor (leftBackMotor_PORT);
    pros::Motor rightFrontMotor (rightFrontMotor_PORT);
    pros::Motor rightMiddleMotor (rightMiddleMotor_PORT);
    pros::Motor rightBackMotor (rightBackMotor_PORT);
    pros::Motor catapultMotor (catapultMotor_PORT);
    pros::Motor intakeMotor(intakeMotor_PORT);
   // pros::ADIDigitalOut climbingPTO (climbingPTO_PORT);
    pros::ADIDigitalOut flapLeft (EXT_flapLeft_PORT);
    pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});
    pros::ADIDigitalIn cataLimit ({{expander_PORT,EXT_cataLimit_PORT}});
    pros::IMU inertia (IMU_PORT);
    
    
    pros::c::imu_reset_blocking(IMU_PORT);
    pros::c::imu_set_heading(IMU_PORT,5);
    pros::c::imu_set_rotation(IMU_PORT, 5);
    

  //  encoderL.reset();
  //  encoderR.reset();
  //  encoderB.reset();
	 pros::lcd::print(4,"count");
    // Controller Setups
 /* vectorR::chassisController chassis;
    chassis.kP = 0;
    chassis.kI = 0;
    chassis.kD = 0;
    chassis.kS = 0;
    chassis.kV = 0;
    chassis.kA = 0;  */
    // Basic chassis initialization, No PID uses BAC coding

}
