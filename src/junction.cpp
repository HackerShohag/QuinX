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
bool allJunctions(String inputstr, String prevstr, String prevstr2)
{
    bool f=0;
    // to turn 90 degree right
   
    // if (inputstr == "00001100" || inputstr == "00001110")
    // {
      
    //     Serial.println("turning right at Lright");
        
    //     turnRight();
    //     //hardBrake(150);
    // }
    // else 
    // if(inputstr=="00000000"){
    //     stop();
    //      if( prevstr == "00000110" ||  prevstr == "00000011"  || prevstr == "00000001" ){
    //      Serial.println("turning right at Lright");
    //     // while(inputstr == "00001111" || inputstr == "00000111" || inputstr == "00000011" || inputstr == "00000001" || inputstr == "01111111" || inputstr == "00111111" || inputstr == "00011111" ){
    //         HardturnRight();
    //       //  inputstr=getbinaryString();
    //     // }
    //       f=1;
    //     }
    //     else if( prevstr == "01100000" ||  prevstr == "11000000"  || prevstr == "10000000" ){
    //      Serial.println("turning right at Lright");
    //     // while(inputstr == "00001111" || inputstr == "00000111" || inputstr == "00000011" || inputstr == "00000001" || inputstr == "01111111" || inputstr == "00111111" || inputstr == "00011111" ){
    //         HardturnRight();
    //       //  inputstr=getbinaryString();
    //     // }
    //       f=1;
    //     }
    //     else {forward();}
    //     f=1;
    // }
    // else if (inputstr=="11111111"){
    //     forward();
    // }
    // if( prevstr == "00000111" ||  prevstr == "00000011"  || prevstr == "00000001" ){
    //      Serial.println("turning right at Lright");
    //     // while(inputstr == "00001111" || inputstr == "00000111" || inputstr == "00000011" || inputstr == "00000001" || inputstr == "01111111" || inputstr == "00111111" || inputstr == "00011111" ){
    //         HardturnRight();
    //       //  inputstr=getbinaryString();
    //     // }
    //       f=1;
    // }
    //to turn 90 degree left
    // else if (inputstr == s4 || inputstr == s5 || inputstr == s6)
    // {
      
    //     Serial.println("turning Left at LLeft");
    //     turnLeft();
    //     //hardBrake(150);
    // }
    // else if(inputstr == "11110000" || inputstr == "11100000" || inputstr == "11000000" || inputstr == "1000000"){
    //      Serial.println("turning hard Left at LLeft");
    //     //hardBrake(10);
    //     HardturnLeft();
    //      f=1;

    // }
    // //  if(prevstr=="11111111" && inputstr=="00011000"){
    // //     calibratemovement();//if there's a plus junction and we need to calibrate
    // // }

    // else if ((prevstr == "00011000" || prevstr == "00111000" || prevstr == "00011100" || prevstr == "00111100") && inputstr == "00000000")
    // {
    //     // LINE break
    //     forward();
    //     hardBrake(150);
    //     String inputstr2=getbinaryString();
    //     ///NEED TO ADD IRSENSOR CODE
    //     //Let k be ir reading boolean
    //     bool k=0;
    //     bool k2=0;

    //     k=haswall(31,30);
    //     k2=haswall(33,32);

    //     if(inputstr2!=s7){
    //         forward();
    //         prevstr2=prevstr;
    //         prevstr=inputstr2;
    //     }
    //     else if(k && k2){
    //         while(k && k2){
    //             int dist1=getDistance(31,30);
    //             int dist2=getDistance(31,30);
    //             int mid=(dist1+dist2)/2;
    //             if(dist1==mid){
    //                 forward();
    //             }
    //             else if(dist1>mid){
    //                 turnLeft();
    //             }
    //             else{
    //                 turnRight();
    //             }
    //              k=haswall(31,30);
    //             k2=haswall(33,32);

    //         }
    //         if(k==0 || k2==0){
    //             forward();
    //         }
    //     }
    //}
    // else if ((prevstr == "00011000" || prevstr == "00111000" || prevstr == "00011100" || prevstr == "00111100") && inputstr == "11111111")
    // {
    //     // plusJunction(inputstr);
    //     /// need to be calibrated
    //     // hardBrake(150);
    //     forward();
    //     // turnLeft();
    //     // turnRight();
    //     hardBrake(150);
    //      f=1;
        
    // }
    // else if (prevstr == "11111111" && inputstr == "00000000")
    // {
    //     // TJunction();
    //     /// NEED to be calibrated
    //     Serial.println("On T junction...");
    //     cnt_tjunc++;
    //     backward();
    //     ///  calibrate if function
    //     if (cnt_tjunc == 1)
    //     {
    //        HardturnLeft();
    //     }
    //     else if (cnt_tjunc == 2)
    //     {
    //        HardturnRight();
    //     }
    //      f=1;
    // }
    // else if (inputstr == "00000000")
    // {
    //     // fullWhite()
    //     backward();
    //     f=1;
    // }
    // else if(prevstr=="11111111" && inputstr=="11111111" && prevstr2=="11111111"){
    //    FinalDest();
    // }
    return f;
}
bool isInverse(String inputstr)
{
    if(inputstr=="11000011" || inputstr=="11100011" || inputstr=="11100111" || inputstr=="11000111" ){
        return true;
    }
    return false;
}

// bool isStartDest()
// {
// }
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
