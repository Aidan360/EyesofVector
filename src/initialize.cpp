#include "main.h"
#include "initialize.hpp"
#include "pros/adi.hpp"
#include "bac.hpp" 
#include "launcher.hpp"
/*
void flyWheelTask() { 
   flyWheel spinnyThing;
   spinnyThing.kS = 0;
   spinnyThing.kV = 0;
   spinnyThing.kP = 0;
   spinnyThing.kI = 0;
   spinnyThing.kD = 0;
   globalRPM = 4200;
   spinnyThing.spinAt(globalRPM);
} */
void odometryTask() { 
  driveTrain.motorPortLeft.push_back(leftFrontMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftMiddleMotor_PORT);
  driveTrain.motorPortLeft.push_back(leftBackMotor_PORT);
  driveTrain.motorPortRight.push_back(rightFrontMotor_PORT);
  driveTrain.motorPortRight.push_back(rightMiddleMotor_PORT);
  driveTrain.motorPortRight.push_back(rightBackMotor_PORT); // change when you actually get the robot  */
  // driveTrain.position[0] = 90;
   //driveTrain.position[1] = 90;
   //driveTrain.heading = 0;
  // driveTrain.OdometryThread();
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
    pros::Motor leftUtilityMotor_initializer (leftUtilityMotor_PORT,pros::E_MOTOR_GEARSET_36,false,pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightUtilityMotor_initializer (rightUtilityMotor_PORT,pros::E_MOTOR_GEARSET_36,false,pros::E_MOTOR_ENCODER_DEGREES);
   // pros::Motor intake_initializer (intakeMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
 //   pros::ADIDigitalOut climbingPTO_initializer (climbingPTO_PORT);
    pros::Imu intertia_initializer (IMU_PORT);
    pros::Optical ColorSensor_initializer (Color_PORT);
    
    // declarations

    pros::Motor leftFrontMotor (leftFrontMotor_PORT);
    pros::Motor leftMiddleMotor (leftMiddleMotor_PORT);
    pros::Motor leftBackMotor (leftBackMotor_PORT);
    pros::Motor rightFrontMotor (rightFrontMotor_PORT);
    pros::Motor rightMiddleMotor (rightMiddleMotor_PORT);
    pros::Motor rightBackMotor (rightBackMotor_PORT);
    pros::Optical ColorSensor (Color_PORT);
    //pros::Motor intakeMotor(intakeMotor_PORT);
   // pros::ADIDigitalOut climbingPTO (climbingPTO_PORT);
    pros::IMU inertia (IMU_PORT);
    

  // Task my_task(flyWheelTask);

  Task odomTask(odometryTask);

   //catapult Catapult; 
   //pros::Task task1(Catapult.catapultThread());



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
