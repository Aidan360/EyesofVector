
#include "main.h"
 // Smart Ports
#define leftFrontMotor_PORT 1 // Speed 
#define leftMiddleMotor_PORT 2 // Speed
#define leftBackMotor_PORT 3 // Speed
#define rightFrontMotor_PORT 4 // Speed
#define rightMiddleMotor_PORT 5 // Speed
#define rightBackMotor_PORT 6 // Speed
#define intakeMotor_PORT 7 // Speed
#define catapultMotor_PORT 8 // Torque?? 
#define expander_PORT 11 // extender for other sensors
#define vision_PORT 10 // vision sensor, may add another.


 // 3 wire ports 
#define encoderLeftTop_PORT 1
#define encoderLeftBottom_PORT 2
#define encoderRightTop_PORT 3
#define encoderRightBottom_PORT 4
#define encoderBackTop_PORT 5
#define encoderBackBottom_PORT 6
#define climbingPTO_PORT 7

 // 3 wire extender
 #define EXT_flapLeft_PORT 'a'
 #define EXT_flapRight_PORT 'b'
 #define EXT_cataLimit_PORT 'c'


extern float ChassisPIDValues[6];






extern void odometryThread();
extern void graphicsThread();
