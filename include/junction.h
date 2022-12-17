#ifndef junction_h
#define junction_h
#include <Arduino.h>

void FinalDest();
//bool isStartDest();

void calibratemovement();
bool allJunctions(String inputstr,String prevstr,String prevstr2);
bool isInverse(String inputstr);
#endif