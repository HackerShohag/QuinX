#include <Arduino.h>
#include "motor.h"
#include "irsensor.h"

float Kp = 0; // related to the proportional control term;
              // change the value by trial-and-error (ex: 0.07).
float Ki = 0; // related to the integral control term;
              // change the value by trial-and-error (ex: 0.0008).
float Kd = 0; // related to the derivative control term;
              // change the value by trial-and-error (ex: 0.6).
int P;
int I;
int D;

int lastError = 0;
boolean onoff = false;

const uint8_t maxspeeda = 150;
const uint8_t maxspeedb = 150;
const uint8_t basespeeda = 100;
const uint8_t basespeedb = 100;

void setup()
{
  // put your setup code here, to run once:
  // Serial.begin(9600);
  // sensorSetup();
  // calibrate();
  // boolean Ok = false;
  // while (Ok == false)
  // {              // the main function won't start until the robot is calibrated
  //   calibrate(); // calibrate the robot for 10 seconds
  //   Ok = true;
  // }
  stop(); // stop the motors
}

void PID_control()
{
  int sensorData[8];
  int position = getPosition(sensorData); // read the current position
  int error = 3500 - position;            // 3500 is the ideal position (the centre)

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  int motorspeed = P * Kp + I * Ki + D * Kd; // calculate the correction
                                             // needed to be applied to the speed

  int motorspeeda = basespeeda + motorspeed;
  int motorspeedb = basespeedb - motorspeed;

  if (motorspeeda > maxspeeda)
  {
    motorspeeda = maxspeeda;
  }
  if (motorspeedb > maxspeedb)
  {
    motorspeedb = maxspeedb;
  }
  if (motorspeeda < 0)
  {
    motorspeeda = 0;
  }
  if (motorspeedb < 0)
  {
    motorspeedb = 0;
  }

  runMotor(motorspeeda, motorspeedb);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // printBinarySensorReadings();
  // forward();
  // delay(2000);
  // hardBrake();
  // delay(5000);
  Serial.begin(9600);
  printBinarySensorReadings();

  PID_control();
}