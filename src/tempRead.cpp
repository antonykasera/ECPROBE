#include <tempRead.h> // Include the header file for temperature reading

#include <Arduino.h>
#include <OneWire.h>           // Include the OneWire library
#include <DallasTemperature.h> // Include the DallasTemperature library for DS18B20 sensor

#define ONE_WIRE_BUS 2

int selectedPin = 2; // default

OneWire oneWire(ONE_WIRE_BUS);       // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature sensor

// Function to set up the temperature reading
void setupTempRead()
{
    Serial.println("------------------------------------");
    Serial.println("Temperature Sensor initialising...");
    sensors.begin();

    Serial.println("Digital pin for temperature sensor: ");

    // Check if user has input a pin number via serial monitor
    while (Serial.available() == 0)
    {
        // wait for input
    }

    int pinNumber = Serial.parseInt();

    // Validate pin number (assuming valid pins are 2 to 12 for Arduino Uno)
    if (pinNumber >= 2 && pinNumber <= 12)
    {
        // If valid, use the user-defined pin
        selectedPin = pinNumber;
        Serial.print("Now using pin ");
        Serial.println(pinNumber);
    }
    else
    {
        // If invalid, use default pin and notify user
        Serial.println("Invalid pin. Defaulted to 2.");
        selectedPin = 2;
    }

    // Set the selected pin as input
    pinMode(selectedPin, INPUT);
    Serial.println("Temperature pin selected succesfully");
    delay(1000);
}

// Function to read temperature multiple times and print average
void tempRead(int samples_temp, int delayTime)
{
    long total = 0;
    for (int i = 0; i < samples_temp; i++)
    {
        // Request temperature from sensor
        sensors.requestTemperatures();

        // Read temperature in Celsius
        float tempC = sensors.getTempCByIndex(0);
        total += tempC;

        // inter-sample delay
        delay(delayTime);
    }

    // Calculate and print average temperature, use long to avoid overflow
    float averageTemp = total / samples_temp;
    Serial.print("Average Temperature: ");
    Serial.print(averageTemp);
    Serial.println(" °C");
}

// Function to get temperature in Celsius
float getTempC()
{
    // Request temperature from sensor
    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);
    return tempC; // Return temperature in Celsius
}
