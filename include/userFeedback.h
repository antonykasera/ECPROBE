#ifndef userFeedback_h
#define userFeedback_h

#include <liquidCrystal_I2C.h>

const int ledDelay = 1000;
const int greenPin = 13;
const int redPin = 12;
const int orangePin = 11;

void ledSequence();

void setupUserFeedback();

void ledFeedback(bool state);

void lcdInitialise();

void lcdPrintTemp(float tempC);

void lcdPrintCond(float condmicroS);

void redLED();

void orangeLED();

void greenLED();

#endif