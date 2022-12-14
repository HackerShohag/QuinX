#ifndef Sonar_h
#define Sonar_h
#include <Arduino.h>

void setupSonar(int echoPin, int trigPin);
int getDistance(int echoPin, int trigPin);

bool hasWall();
#endif