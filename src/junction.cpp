#include <Arduino.h>
#include "junction.h"
#include "motor.h"
#include "irsensor.h"
#include "sonar.h"

String s1 = "00011111";
String s2 = "00111111";
String s3 = "01111111";
String s4 = "11111000";
String s5 = "11111100";
String s6 = "11111110";
String s7 = "00000000";
String s8 = "11111111";
String s9 = "00011000";

bool f = 0;
int cnt_tjunc = 0;
void allJunctions(String inputstr, String prevstr, String prevstr2)
{

    // to turn 90 degree right
    if (inputstr == s1 || inputstr == s2 || inputstr == s3)
    {
      
        Serial.println("turning hard right at Lright");
       HardturnRight();
        //hardBrake(150);
    }
    // to turn 90 degree left
    else if (inputstr == s4 || inputstr == s5 || inputstr == s6)
    {
      
        Serial.println("turning hard Left at LLeft");
       HardturnLeft();
        //hardBrake(150);
    }
    //  if(prevstr=="11111111" && inputstr=="00011000"){
    //     calibratemovement();//if there's a plus junction and we need to calibrate
    // }

    else if ((prevstr == "00011000" || prevstr == "00111000" || prevstr == "00011100" || prevstr == "00111100") && inputstr == "00000000")
    {
        // LINE break
        forward();
        hardBrake(150);
        String inputstr2=getbinaryString();
        ///NEED TO ADD IRSENSOR CODE
        //Let k be ir reading boolean
        bool k=0;
        if(inputstr2!=s7 || k){
            forward();
            prevstr2=prevstr;
            prevstr=inputstr2;
        }
        // else if(k){
        //     while(k){
        //         //k=haswall();
        //     }
        //     if(k==0){
        //         forward();
        //     }
        // }
    }
    else if ((prevstr == "00011000" || prevstr == "00111000" || prevstr == "00011100" || prevstr == "00111100") && inputstr == "11111111")
    {
        // plusJunction(inputstr);
        /// need to be calibrated
        // hardBrake(150);
        forward();
        // turnLeft();
        // turnRight();
        hardBrake(150);
        
    }
    else if (prevstr == "11111111" && inputstr == "00000000")
    {
        // TJunction();
        /// NEED to be calibrated
        Serial.println("On T junction...");
        cnt_tjunc++;
        backward();
        ///  calibrate if function
        if (cnt_tjunc == 1)
        {
           HardturnLeft();
        }
        else if (cnt_tjunc == 2)
        {
           HardturnRight();
        }
    }
    // else if (inputstr == "00000000")
    // {
    //     // fullWhite()
    //     backward();
    // }
    // else if(prevstr=="11111111" && inputstr=="11111111" && prevstr2=="11111111"){
    //    FinalDest();
    // }
}
bool isInverse(String inputstr)
{
    if(inputstr=="11000011" || inputstr=="11100011" || inputstr=="11100111" || inputstr=="11000111" ){
        return true;
    }
    return false;
}

bool isStartDest()
{
}
void FinalDest()
{
    Serial.println("Final dest reached");
    hardBrake(150);
    stop();
}

void calibratemovement()
{
    // backward();
    // hardBrake(150);
    // turnLeft();
    // turnRight();
    // hardBrake(150);
}
