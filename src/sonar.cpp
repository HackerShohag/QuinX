#include <Arduino.h>
#include "sonar.h"



long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement

void setupSonar(int echoPin, int trigPin)
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
}
int haswall(int echoPin, int trigPin){
    int m=getDistance(echoPin,trigPin);
    if(m>0 && m<30){
        return 1;
    }
    return 0;
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

