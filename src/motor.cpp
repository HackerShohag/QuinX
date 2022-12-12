#include <Arduino.h>
#include "motor.h"

int motor1pin1 = 11;
int motor1pin2 = 12;
int motor2pin1 = 9;
int motor2pin2 = 10;
int ena = 8;
int enb = 13;

void motorSetup()
{
    // put your setup code here, to run once:

    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);

    pinMode(ena, OUTPUT);
    pinMode(enb, OUTPUT);
}

void forward()
{
    // PWM pin for speed control
    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    // motor singals
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}

void backward()
{
    // PWM pin for speed control
    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    // motor singals
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
}

void turnLeft()
{
    // PWM pin for speed control
    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    // motor singals
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}

void turnRight()
{
    // PWM pin for speed control
    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    // motor singals
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
}

void stop()
{
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);
}

void hardBrake()
{
    backward();
    delay(150);
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);
}

void runMotor(int motorspeeda, int motorspeedb)
{
    analogWrite(ena, motorspeeda);
    analogWrite(enb, motorspeedb);

    // enabling motors
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
}