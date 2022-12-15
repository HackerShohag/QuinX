#ifndef junction_h
#define junction_h
#include <Arduino.h>

void TJunction();
String plusJunction(String inputstr);
void LRight(String inputstr);
void LLeft(String inputstr);
void FinalDest();
bool isStartDest();
void lineBreak();
void calibratemovement();
#endif