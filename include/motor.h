#ifndef Motor_h
#define Motor_h
#include <Arduino.h>
#define DEFAULTSPEED 255

void motorSetup();
void forward();
void backward();
void runMotor(int motorspeeda, int motorspeedb);
void turnLeft();
void turnRight();

void hardBrake();
void stop();

#endif