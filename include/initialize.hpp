
#include "main.h"
 // Smart Ports
#define leftFrontMotor_PORT 1 // Speed 
#define leftMiddleMotor_PORT 2 // Speed
#define leftBackMotor_PORT 3 // Speed
#define rightFrontMotor_PORT 4 // Speed
#define rightMiddleMotor_PORT 5 // Speed
#define rightBackMotor_PORT 6 // Speed
#define intakeMotor_PORT 7 // Speed
#define flyWheelMotor_PORT 8 // Torque?? 
#define expander_PORT 11 // extender for other sensors
#define vision_PORT 12 // vision sensor, may add another.
#define IMU_PORT 11 // Port for Temporary IMU 


 // 3 wire ports 
#define encoderLeftTop_PORT 1
#define encoderLeftBottom_PORT 2
#define encoderRightTop_PORT 3
#define encoderRightBottom_PORT 4
#define encoderBackTop_PORT 5
#define encoderBackBottom_PORT 6
//#define climbingPTO_PORT 7


 #define wings_PORT 'f'
 #define blocker_PORT 'g'

 // 3 wire extender
 #define EXT_flapLeft_PORT 'f'
 #define EXT_flapRight_PORT 'f'
 #define EXT_cataLimit_PORT 'c'
 #define indexer_PORT 'b'


extern float ChassisPIDValues[6];




extern double sgn(double x);
extern double abso(double x);
extern void odometryThread();
extern void graphicsThread();
