#ifndef conductanceRead_h
#define conductanceRead_h

//#include <Arduino.h>
#include <FreqCount.h>
#include <math.h>

unsigned long freq;
float conductance;
int sum = 0; 
float average = 0;
float samples_cond = 10;
float temperatureCoef= 0.02;
float tempRTP = 25.0;
float conductanceRTP = 0;
int delayTime = 0;

void setupFrequencyCounter(){
  FreqCount.begin(1000);
}

void debugFrequency(){
if (FreqCount.available()){
  freq = FreqCount.read();
  Serial.println(freq);
 }
} 

float getConductanceRTP(float tempDeg){
  for (int i = 0; i < samples_cond; i++) {
    sum += freq;
    delay(delayTime); 
  }

  average = sum / samples_cond;
  conductance=pow(10,6)*exp((-3.8946 + sqrt(pow(3.8946,2) - 4*0.1708*(29.4363 - log(freq)))) / (2*0.1708));
  
  conductanceRTP=conductance/(1+temperatureCoef*(tempDeg-25));
  return conductanceRTP; 
}

void serialPlotFreq(){
  Serial.println(average);
}

void serialPrintConductance(){
  Serial.print("Conductance: ");
  Serial.print(conductance);
  Serial.println(" uS ");
}
 
  //
  //
  //                   
  //}

  //average = sum / 10.0;
  //float conductance = exp((-3.8946 + sqrt(pow(3.8946,2) - 4*0.1708*(29.4363 - log(freq)))) / (2*0.1708));
  //float conductance=pow(10,6)*exp((-3.8946 + sqrt(pow(3.8946,2) - 4*0.1708*(29.4363 - log(freq)))) / (2*0.1708)); 
  //Serial.print("Conductance: ");
  //Serial.print(conductance);
  //Serial.println(" uS");
#endif