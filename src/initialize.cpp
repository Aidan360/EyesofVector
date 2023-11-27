#include "main.h"
#include "initialize.hpp"
#include "pros/adi.hpp"
#include "bac.hpp" 
#include "launcher.hpp"

void flyWheelTask() {
   
   /* Mini logs to know what I did
    ks =1 
    ks = 100
    ks 10000
    ks 500
    kS = 700
    kS = 1000
    kS = 1100
    kS = 1500
    kS = 2000, upper limit
    kS = 1900 lower limit
    ks = 1950
    kS = 1975 upper limit
    kS = 1960
    kS = 1955
    kS = 1957 no move
    kS = 1959 move
    kS = 1958 no move 
    kS = 1959 no move
    kS = 1960
    kS = 1965
    kS = 1970
    kS = 1965 
    kS = 1970
    kS = 1975
    kS = 1980 
    kS = 1995
    kS = 2000 no movement 
    kS = 2100
    kS = 2200
    kS = 2300

    kV = 1
    kV = 50 upper
    kV = 25 lower
    kV = 35
    Kv = 40
    kP = 1
    kP = 10
   */ 

   flyWheel spinnyThing;
   spinnyThing.kS = 2200; // 2200
   spinnyThing.kV = 36;
   spinnyThing.kP = 10;
   spinnyThing.kI = .1;
   spinnyThing.kD = 0;
   spinnyThing.flyWheelPort = flyWheelMotor_PORT;
   globalRPM = 2000;
   spinnyThing.spinAt(globalRPM);

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
    pros::c::imu_set_heading(IMU_PORT,5);
    pros::c::imu_set_rotation(IMU_PORT, 5);
  
  Task my_task(flyWheelTask);

  
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
