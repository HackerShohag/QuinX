#include <Arduino.h>
#include "junction.h"
#include "motor.h"
#include "irsensor.h"


String s1="00011111";
String s2="00111111";
String s3="01111111";
String s4="11111000";
String s5="11111100";
String s6="11111110";
String s7="00000000";
String s8="11111111";
String s9="00011000";

bool f=0;
int cnt_tjunc=0;

void TJunction(){
    /// NEED to be calibrated
    Serial.println("On T junction...");
    cnt_tjunc++;
    backward();
    ///  calibrate if function 
    if(cnt_tjunc==1){
        turnLeft();
    }
    else if(cnt_tjunc==2){
        turnRight();
    }
   
    

}
String plusJunction(String inputstr){
  ///need to be calibrated
   //hardBrake(150);
   forward();
   //turnLeft();
   //turnRight();
   hardBrake(150);
}
bool isStartDest(){


}
void FinalDest(){
    Serial.println("Final dest reached");
    hardBrake(150);
    stop();

}
void lineBreak(){   
    forward();
}
void calibratemovement(){
    //backward();
    //hardBrake(150);
    //turnLeft();
    //turnRight();
    //hardBrake(150);
}
void fullWhite(String inputstr){
        backward();
        hardBrake(150);
  
}

void LRight(String inputstr){
    // to turn 90 degree right
    if(inputstr==s1 || inputstr==s2 || inputstr==s3){
    hardBrake(150);
    Serial.println("turning hard right at Lright");
    turnRight();
    }
}
void LLeft(String inputstr){
    // to turn 90 degree left
     if(inputstr==s4 || inputstr==s5 || inputstr==s6){
    hardBrake(150);
    Serial.println("turning hard Left at LLeft");
    turnLeft();
    }
}