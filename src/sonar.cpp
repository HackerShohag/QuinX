#include <Arduino.h>
#include "sonar.h"

long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement

void setupSonar(int echoPin, int trigPin)
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
}

int getDistance(int echoPin, int trigPin)
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    return distance;
}

bool hasWall()
{
  int left = 0, right = 0;
  right=getDistance();
  left=getDistance();
  if(right>2 && right<30)return true;
  if(left>2 && left<30)return true;
  return false;
}