#include <Arduino.h>
#include "motor.h"
#include "irsensor.h"
#include "sonar.h"
#include "junction.h"

int sonarEcho1 = 31;
int sonarTrig1 = 30;

int sonarEcho2 = 33;
int sonarTrig2 = 32;

String strarray[10];
bool fk=0;
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
bool st=0,en=0;
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

  runMotor(motorspeeda, motorspeedb);
}

void loop(){
  int cnt=0;
    if(fk==0){
        fk=1;
        for(int i=0;i<10;i++){
        strarray[i]="11111111";
        }
    }
   String inputstr=getbinaryString();
//    //bool cond=allJunctions(inputstr,prevstr,prevstr2);
    for(int i=1;i<10;i++){
        strarray[i]=strarray[i-1];
    }

    strarray[0]=inputstr;

    for(int i=0;i<10;i++){
        if(strarray[i]=="11111111"){
          cnt++;
        }
        else break;
      }
      //Cnt need to be calibrated
    if(cnt>5 && st==0){
      //START
      forward();
      delay(150);
      st=1;
    }
    else if(cnt>6 && st==1){
      //END
      stop();
      delay(2000);
    }
   else if(inputstr=="00000000"){
      stop();
      bool m=0;
      for(int i=1;i<10;i++){
        m=1;
         if(strarray[i] == "11111100" || strarray[i] == "11111000" || strarray[i] == "11110000" || strarray[i] == "11100000" ||  strarray[i] == "11000000"  || strarray[i] == "10000000" ){
         Serial.println("turning Hard Right");
        // while(inputstr == "00001111" || inputstr == "00000111" || inputstr == "00000011" || inputstr == "00000001" || inputstr == "01111111" || inputstr == "00111111" || inputstr == "00011111" ){
            //HardturnLeft(100);
            HardturnRight(120);
            break;
            //stop();
          //  inputstr=getbinaryString();
        // }
         
        }
        else if(strarray[i]  == "00111111" || strarray[i]  == "00011111" || strarray[i]  == "00001111" || strarray[i]  == "00000111" ||  strarray[i]  == "00000011"  || strarray[i]  == "00000001" ){
         Serial.println("turning Hard Right");
        // while(inputstr == "00001111" || inputstr == "00000111" || inputstr == "00000011" || inputstr == "00000001" || inputstr == "01111111" || inputstr == "00111111" || inputstr == "00011111" ){
            HardturnLeft(120);
            break;
            //HardturnRight(100);
            //stop();
          //  inputstr=getbinaryString();
        //}
         
        }
        else if( strarray[i] == "00011000" || strarray[i] == "00001100"  || strarray[i] == "00110000"){
         //LINE BREAK
         forward();
         delay(150);
          //stop();
          break;
         
        }

        else m=0;
      }

      if(m==0){
        //Dead END!!
        backward();
        delay(150);
        stop();    
      }
      else PID_control();
           
    }
    // else if (inputstr=="11111111"){
    //     forward();
    // }


  else PID_control();

//    prevstr2=prevstr;
//    prevstr=inputstr;
    // forward();
    // delay(1000);
    // HardturnRight(160);
    // stop();
    //  delay(1000);
   //printBinarySensorReadingsDigital();
}