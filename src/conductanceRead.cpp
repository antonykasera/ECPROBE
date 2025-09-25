#include <FreqCount.h>

#include <math.h>

// Global variables and constants
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
const double m = -1.0 / 0.907;

float dist = 0.3; // distance between electrodes in cm
float dia = 0.08; // diameter of electrode in cm
float length = 1.1;

float Area = 2 * 3.14159 * dia * length; // electrode area in cm^2

float cellConstant = dist / Area; // in cm^-1

// Function to set up frequency counter
void setupFrequencyCounter()
{
    // Initialize FreqCount library to count frequency on pin 5
    FreqCount.begin(1000);
}

// Function to debug frequency readings
void debugFrequency()
{
    if (FreqCount.available())
    {
        // Read frequency value
        freq = FreqCount.read();
        Serial.println(freq);
        Serial.println(cellConstant);
    }
}

// Function to get conductance and related values
void getCond()
{
    if (FreqCount.available())
    {
        // Read frequency value
        freq = FreqCount.read();
        Serial.print("Frequency: ");
        Serial.print(freq);
        Serial.println(" Hz\t\t\t");
        Serial.println("--------------------------------");

        // Serial.println(cellConstant);
    }

    // Calculate resistance and conductance
    float res = pow(freq / c, m);
    Serial.print("Resistance:\033[32m ");
    Serial.print(res, 1);
    Serial.println("\033[0m\t\t\t");
    Serial.println("--------------------------------");

    // conductance in microSiemens
    conductance = 1e6 * cellConstant / res; // in microS
    Serial.print("Conductance: \033[32m");
    Serial.print(conductance, 1);
    Serial.println("\033[0m µS \t\t\t");
    Serial.println("--------------------------------");
    Serial.print("RTP Adjusted Conductance:\033[32m ");

    // conductance adjusted to room temperature of 25C
    conductanceRTP = conductance / (1 + temperatureCoef * (tempRTP - 25));
    Serial.print(conductanceRTP, 1);
    Serial.println("\033[0m µS @ 25C\t\t\t");
}

// Function to get conductance adjusted to a specific temperature
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
    float res = pow(average / c, m);
    conductance = 1e6 * cellConstant / res; // in microS

    conductanceRTP = conductance / (1 + temperatureCoef * (tempDeg - 25));
    return conductanceRTP;
}

// Function to send frequency data to serial plotter for visualization/graphing
void serialPlotFreq()
{
    Serial.println(average);
}

// Function to send conductance
void serialPrintConductance()
{
    Serial.print("Conductance: ");
    Serial.print(conductance, 1);
    Serial.println(" uS ");
}
