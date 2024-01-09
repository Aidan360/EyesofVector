#include "main.h"
#include "initialize.hpp"
#include "pros/adi.hpp"
#include "bac.hpp" 
#include "launcher.hpp"
#include "pros/motors.h"

void flyWheelTask() {
   
   /* Mini logs to know what I did
      2600
      2300
      kv later 
      30 or 25
   */ 

   flyWheel spinnyThing; 
   spinnyThing.kS = 2300; // 2300
   spinnyThing.kV = 40; // 36
   spinnyThing.kP = 30; // 10
   spinnyThing.kI = 0.05; // no use 
   spinnyThing.kD = 0.75;
   spinnyThing.flyWheelPort = flyWheelMotor_PORT;
   globalRPM = 2000;
   //spinnyThing.spinAt(globalRPM);

}

void odometryTask() { 
  driveTrain.motorPortLeft.push_back(leftFrontMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftMiddleMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftBackMotor_PORT);
  driveTrain.motorPortRight.push_back(rightFrontMotor_PORT);
  driveTrain.motorPortRight.push_back(rightMiddleMotor_PORT);
  driveTrain.motorPortRight.push_back(rightBackMotor_PORT);
  driveTrain.wheelSize = 3.25;
  driveTrain.trackLength = 13.7; // change when you actually get the robot  */
   driveTrain.position[0] = 90;
   driveTrain.position[1] = 90;
   driveTrain.heading = 0;
   driveTrain.OdometryThread();
} 

void initialize() {
	// initializers
    pros::lcd::initialize();
    pros::Motor leftFrontMotor_initializer (leftFrontMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor leftMiddleMotor_initializer (leftMiddleMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);  
    pros::Motor leftBackMotor_initializer (leftBackMotor_PORT, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightFrontMotor_initializer (rightFrontMotor_PORT, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightMiddleMotor_initializer (rightMiddleMotor_PORT, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); 
    pros::Motor rightBackMotor_initializer (rightBackMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
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
    pros::Motor intakeMotor(intakeMotor_PORT);
   // pros::ADIDigitalOut climbingPTO (climbingPTO_PORT);
    pros::ADIDigitalOut flapLeft (EXT_flapLeft_PORT);
    pros::ADIDigitalOut flapRight ({{expander_PORT,EXT_flapRight_PORT}});
    pros::ADIDigitalIn cataLimit ({{expander_PORT,EXT_cataLimit_PORT}});
    pros::IMU inertia (IMU_PORT);
    
    
    pros::c::imu_reset_blocking(IMU_PORT);
  //  pros::c::imu_set_heading(IMU_PORT,5);
  //  pros::c::imu_set_rotation(IMU_PORT, 5);
  
   //Task my_task(flyWheelTask);
   //Task odomTask(odometryTask);
   driveTrain.position[0] = 90;
   driveTrain.position[1] = 90;
   
   //catapult Catapult; 
   //pros::Task task1(Catapult.catapultThread());

		intakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      leftFrontMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      leftMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      leftBackMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      rightFrontMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      rightMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      rightMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      

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
