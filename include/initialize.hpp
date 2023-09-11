#include "main.h"

 // Smart Ports
#define leftFrontMotor_PORT 1 
#define leftMiddleMotor_PORT 2
#define leftBackMotor_PORT 3 
#define rightFrontMotor_PORT 4
#define rightMiddleMotor_PORT 5
#define rightBackMotor_PORT 6
#define intakeMotor_PORT 7
#define slingShotMotor_PORT 8 

 // 3 wire ports 
#define encoderLeftTop_PORT 1
#define encoderLeftBottom_PORT 2
#define encoderRightTop_PORT 3
#define encoderRightBottom_PORT 4
#define encoderBackTop_PORT 5
#define encoderBackBottom_PORT 6
#define climbingPTO_PORT 7
#define intakePTO_PORT 8 
 // 3 wire extender

extern float ChassisPIDValues[6];





extern void odometryThread();
extern void graphicsThread();
