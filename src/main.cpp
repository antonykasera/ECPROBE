// Main program file for Soil EC and Temperature Sensor
// Uses C++11 standard
// Developed by Antony Kasera(https://github.com/antonykasera/ECPROBE/)
// Actively in development. Use at your own risk.

#include <Arduino.h>
#include <conductanceRead.h>
#include <tempRead.h>
#include <userFeedback.h>

const int pulsePin = 5;
const long baudRate = 9600;
float tempC = 0.0;
float condmicroS = 0;

void setup()
{

  Serial.begin(baudRate);
  lcdInitialise();
  setupFrequencyCounter();
  setupTempRead();
  setupUserFeedback();
  // debugFrequency();
  delay(2000);
}

void loop()
{
debugFrequency();
Serial.println("-----------------------");
  tempC = getTempC();
  Serial.print("Substrate Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

 // condmicroS = getConductanceRTP(tempC);
  //Serial.print("Conductance at 25°C: ");
  //Serial.print(condmicroS);
  //Serial.println(" μS");

  getCond();
/*
  if (condmicroS < 60)
  {
    redLED();
  }
  else if (condmicroS > 60 && condmicroS < 90)
  {
    orangeLED();
  }
  else if (condmicroS > 90)
  {
    greenLED();
  }
  else
  {
    Serial.println("Check for circuit error!");
    redLED();
    orangeLED();
  }

  delay(5000);
  */
}
