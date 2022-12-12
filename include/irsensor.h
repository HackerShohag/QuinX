#ifndef _IR
#define _IR 1

void calibrate();
void sensorSetup();
void printBinarySensorReadings();

void readData(int sensorReadings[]);
int getPosition(int sensorReadings[]);
void readDataDigital(int sensorReadingsDigital[]);

#endif // _IR