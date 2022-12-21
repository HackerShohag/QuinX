#include <Arduino.h>
#include "motor.h"
#include "irsensor.h"
#include "sonar.h"
#include "junction.h"

int sonarEcho1 = 31;
int sonarTrig1 = 30;

int sonarEcho2 = 33;
int sonarTrig2 = 32;
String prevstr="",prevstr2="",prevstr3="",prevstr4="",prevstr5="",prevstr6="",prevstr7="",prevstr8="";
float Kp = 0.07; // related to the proportional control term;
              // change the value by trial-and-error (ex: 0.07).
float Ki = 0.0008; // related to the integral control term;
              // change the value by trial-and-error (ex: 0.0008).
float Kd = 0.6; // related to the derivative control term;
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
  Serial.begin(9600);
  // sensorSetup();
  // calibrate();
  // boolean Ok = false;
  // while (Ok == false)
  // {              // the main function won't start until the robot is calibrated
  //   calibrate(); // calibrate the robot for 10 seconds
  //   Ok = true;
  // }
  setupSonar(sonarEcho1, sonarTrig1);
  setupSonar(sonarEcho2, sonarTrig2);
  stop(); // stop the motors
}

int mtrl = 0, mtrr = 0;

void PID_control()
{
  int sensorData[8];
  int position = getPosition(sensorData); // read the current position
  // Serial.print("\t\t\t\t\tPosition: ");
  // Serial.println(position);
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
  mtrl = motorspeeda;
  mtrr = motorspeedb;
//   runMotor(motorspeeda, motorspeedb);
}

void loop(){
   String inputstr=getbinaryString();
//    //bool cond=allJunctions(inputstr,prevstr,prevstr2);

    while (inputstr=="00000000") {
        hardBrake(100);
        inputstr=getbinaryString();
        runMotor(mtrl, mtrr);
    }
    PID_control();
    runMotor(mtrl, mtrr);

  prevstr2=prevstr;
  prevstr=inputstr;
  
//    prevstr2=prevstr;
//    prevstr=inputstr;
    // forward();
    // delay(1000);
    // HardturnRight(160);
    // stop();
    //  delay(1000);
   //printBinarySensorReadingsDigital();
}