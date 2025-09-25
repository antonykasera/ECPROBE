#include <FreqCount.h>

#include <math.h>

unsigned long freq;
float conductance;
int sum = 0;
float average = 0;
int samples_cond = 10;
float temperatureCoef = 0.02;
float tempRTP = 25.0;
float conductanceRTP = 0;
float resistance = 0;
int delayTime = 10;

const double c = 2.1e6;
const double m = -1.0/0.907;


float dist = 0.3;
float dia = 0.08;
float length = 1.1;

float Area = 2 * 3.14159 * dia * length; // electrode area in cm^2

float cellConstant = dist / Area; // in cm^-1
void setupFrequencyCounter()
{
    FreqCount.begin(1000);
}

void debugFrequency()
{
    if (FreqCount.available())
    {
        freq = FreqCount.read();
        Serial.println(freq);
        Serial.println(cellConstant);
    }
}
void getCond(){
    if (FreqCount.available())
    {
        freq = FreqCount.read();
        Serial.println(freq);
        // Serial.println(cellConstant);
    }
    float res = pow(freq/c, m);
    Serial.print("Resistance: ");
    Serial.println(res,1);
    conductance = 1e6*cellConstant /res; // in microS
    Serial.print("Conductance: ");
    Serial.print(conductance,1);
    Serial.println(" uS ");
    Serial.print("RTP Adjusted Conductance: ");
    conductanceRTP = conductance / (1 + temperatureCoef * (tempRTP - 25));
    Serial.print(conductanceRTP,1);
    Serial.print(" uS At 25C");
    Serial.println("---------------");
    delay(5000);
}

float getConductanceRTP(float tempDeg)
{
    sum = 0;
    for (int i = 0; i < samples_cond; i++)
    {
         if (FreqCount.available())
    {
        freq = FreqCount.read();
        // Serial.println(freq);
        // Serial.println(cellConstant);
    }
        sum += freq;
        delay(0);
    }

    average = sum / samples_cond;
    float res = pow(average/c, m);
    conductance = 1e6*cellConstant /res; // in microS
    
    conductanceRTP = conductance / (1 + temperatureCoef * (tempDeg - 25));
    return conductanceRTP;
}

void serialPlotFreq()
{
    Serial.println(average);
}

void serialPrintConductance()
{
    Serial.print("Conductance: ");
    Serial.print(conductance,1);
    Serial.println(" uS ");
}

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