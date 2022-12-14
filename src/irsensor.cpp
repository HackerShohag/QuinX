#include <Arduino.h>
#include "irsensor.h"

const int numOfSensors = 8;
int max = 0, min = 1200;
int sensorPins[numOfSensors] = {A0, A1, A2, A3, A4, A5, A6, A7};
int sensorThresholds[numOfSensors] = {850, 850, 850, 850, 850, 850, 850, 850};
int sensorThreshold = 850;
int sensorReadingsAnalog[numOfSensors] = {0, 0, 0, 0, 0, 0, 0, 0};
bool sensorReadingsDigital[numOfSensors] = {0, 0, 0, 0, 0, 0, 0, 0};

void readDataAnalog(int sensorReadingsAnalog[])
{
    for (int i = 0; i < numOfSensors; i++)
    {
        sensorReadingsAnalog[i] = analogRead(sensorPins[i]);
        min = min < sensorReadingsAnalog[i] ? min : sensorReadingsAnalog[i];
        max = max < sensorReadingsAnalog[i] ? sensorReadingsAnalog[i] : max;
    }
}
void readDataDigital(int sensorReadingsDigital[])
{
    for (int i = 0; i < numOfSensors; i++)
    {
        sensorReadingsDigital[i] = digitalRead(sensorPins[i]);
    }
}

void calibrate()
{
    Serial.println("Put on black within 5sec");
    delay(5000);
    int sensorReadingsAnalog1[numOfSensors];
    readDataAnalog(sensorReadingsAnalog1);
    int x = (min + max) / 2;

    Serial.println("Put on white within 5sec");
    delay(5000);
    int sensorReadingsAnalog2[numOfSensors];
    readDataAnalog(sensorReadingsAnalog2);
    int y = (min + max) / 2;

    for (int i = 0; i < numOfSensors; i++)
    {
        sensorThresholds[i] = (sensorReadingsAnalog1[i] + sensorReadingsAnalog2[i]) / 2;
    }

    sensorThreshold = (x + y) / 2;
    delay(5);
}

void sensorSetup()
{
    for (int i = 0; i < numOfSensors; i++)
        pinMode(sensorPins[i], INPUT);
}

void printBinarySensorReadingsAnalog()
{
    for (int i = 0; i < numOfSensors; i++)
    {
        Serial.print(analogRead(sensorPins[i]));
        Serial.print(" ");
    }
    Serial.print("\tThreshold: ");
    Serial.println(sensorThreshold);
    delay(250);
}

void printBinarySensorReadingsDigital()
{
    for (int i = 0; i < numOfSensors; i++)
    {
        Serial.print(digitalRead(sensorPins[i]));
        Serial.print(" ");
    }
    Serial.print("\tThreshold: ");
    Serial.println(sensorThreshold);
    delay(250);
}

int getPosition(int sensorReadingsAnalog[])
{
    int position = 0;
    int v = 0;
    readDataAnalog(sensorReadingsAnalog);
    for (int i = 0; i < numOfSensors; i++)
    {
        if (sensorReadingsAnalog[i] > sensorThreshold)
        {
            position += i * 1000;
            v++;
        }
    }
    if (v==0) return 0;
    return position/v;
}