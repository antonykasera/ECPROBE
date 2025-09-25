#ifndef tempread_h
#define tempRead_h

#include <OneWire.h>
#include <DallasTemperature.h>

void setupTempRead();

void tempRead(int samples_temp = 5, int delayTime = 10);

void tempReadOnce();

float getTempC();

#endif