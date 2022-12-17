#ifndef _IR
#define _IR
#include <string.h>

void calibrate();
void sensorSetup();
void printBinarySensorReadingsAnalog();
String  getbinaryString();
int getPosition(int sensorReadings[]);
void readDataDigital(int sensorReadingsDigital[]);
void readDataAnalog(int sensorReadingsAnalog[]);
void printBinarySensorReadingsDigital();
#endif // _IR