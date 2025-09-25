// Main program file for Soil EC and Temperature Sensor
// Uses C++11 standard
// Developed by Antony Kasera(https://github.com/antonykasera/ECPROBE/)
// Actively in development. Use at your own risk.

// Libraries and Header files:
#include <Arduino.h>
#include <conductanceRead.h>
#include <tempRead.h>
#include <userFeedback.h>

// Pin and variable definitions
const int pulsePin = 5;
const long baudRate = 9600;
float tempC = 0.0;
float condmicroS = 0;

void setup()
{

  Serial.begin(baudRate);
  Serial.print("\033[2J"); // Clear screen
  Serial.print("\033[H");  // Cursor to home position

  // lcdInitialise(); // Define your own function in userFeedback.h

  // Sets up FreqCount library
  setupFrequencyCounter();

  // Sets up temperature sensor(DS18B20)
  setupTempRead();

  // Sets up user feedback(LEDs, Buzzer etc), more functions can be added in userFeedback.h
  setupUserFeedback();

  // debugFrequency(); // Uncomment to debug 555 timer frequency output

  delay(3000); // Wait for everything to stabilise

  Serial.print("\033[2J"); // Clear screen
  Serial.print("\033[H");  // Cursor to home position
}

void loop()
{
  // Check the curreent state of the terminal, simple
  static bool firstPrint = true;
  if (!firstPrint)
  {
    // Move cursor up by the number of lines you are printing
    Serial.print("\033[13A");
  }
  else
  {
    firstPrint = false; // skip moving cursor the first time
  }

  // debugFrequency();
  Serial.println("--------------------------------");
  tempC = getTempC();
  Serial.print("Substrate Temperature: \033[32m");
  Serial.print(tempC);
  Serial.println("\033[0m °C\t\t\t");
  Serial.println("--------------------------------");

  // condmicroS = getConductanceRTP(tempC);
  // Serial.print("Conductance at 25°C: ");
  // Serial.print(condmicroS);
  // Serial.println(" μS");
  getCond();
  Serial.println("--------------------------------");

  delay(5000);

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
