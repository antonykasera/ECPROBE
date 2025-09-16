#ifndef tempread_h
#define tempRead_h

//#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
int selectedPin = 2; // default

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setupTempRead(){
    Serial.println("------------------------------------");
    Serial.println("Temperature Sensor initialising...");
    sensors.begin();

    Serial.println("Digital pin for temperature sensor: ");

    while (Serial.available() == 0){
      //wait for input
    } 

    int pinNumber = Serial.parseInt();

    if (pinNumber >= 2 && pinNumber <= 12){
        selectedPin = pinNumber;   
        Serial.print("Now using pin ");
        Serial.println(pinNumber);
        Serial.println("Temperature pin selected succesfully");
    } else {
        Serial.println("Invalid pin. Defaulted to 2.");
        selectedPin = 2;
    }
    delay(1000);
}

void tempRead(int samples_temp = 5,int delayTime = 10 ){
    long total = 0;
    for (int i = 0; i < samples_temp; i++)
    {
        sensors.requestTemperatures();
        float tempC = sensors.getTempCByIndex(0);
        total+= tempC;
        delay(delayTime);
    }
    
    float averageTemp = total / samples_temp;
    Serial.print("Average Temperature: ");
    Serial.print(averageTemp);
    Serial.println(" °C");
}

void tempReadOnce(){
    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println(" °C");
}

float getTempC(){
    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);
    return tempC;
}

#endif