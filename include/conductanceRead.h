#ifndef conductanceRead_h
#define conductanceRead_h

// #include <Arduino.h>
#include <FreqCount.h>
#include <math.h>

void setupFrequencyCounter();

void debugFrequency();

float getConductanceRTP(float tempDeg);

void serialPlotFreq();

void getCond();

void serialPrintConductance();

//
//
//
//}

// average = sum / 10.0;
// float conductance = exp((-3.8946 + sqrt(pow(3.8946,2) - 4*0.1708*(29.4363 - log(freq)))) / (2*0.1708));
// float conductance=pow(10,6)*exp((-3.8946 + sqrt(pow(3.8946,2) - 4*0.1708*(29.4363 - log(freq)))) / (2*0.1708));
// Serial.print("Conductance: ");
// Serial.print(conductance);
// Serial.println(" uS");
#endif