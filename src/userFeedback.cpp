#include <userFeedback.h>

#include <Arduino.h>

// Pin definitions for LEDs and buzzer in userFeedback.h

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
// LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

// Function to run an LED sequence
void ledSequence()
{
    digitalWrite(greenPin, HIGH);
    delay(ledDelay);
    digitalWrite(greenPin, LOW);
    digitalWrite(orangePin, HIGH);
    delay(ledDelay);
    digitalWrite(orangePin, LOW);
    digitalWrite(redPin, HIGH);
    delay(ledDelay);
    digitalWrite(redPin, LOW);
}

// Function to set up user feedback (LEDs, Buzzer etc)
void setupUserFeedback()
{
    Serial.println("------------------------------------");
    Serial.println("Setup User Feedback");
    Serial.println("Enter '1' for LED feedback, '0' for no feedback:");

    // Check if user has input a pin number via serial monitor
    while (Serial.available() == 0)
    {
        // wait for user input
    }

    // Read the user input
    char input = Serial.read();
    if (input == '1')
    {
        // If user wants LED feedback, set the pins as output
        pinMode(greenPin, OUTPUT);
        pinMode(redPin, OUTPUT);
        pinMode(orangePin, OUTPUT);

        Serial.println("LED feedback enabled.");
        ledSequence();
    }
    else
    {
        // If user does not want LED feedback, set pins as input to save power
        pinMode(greenPin, INPUT);
        pinMode(redPin, INPUT);
        pinMode(orangePin, INPUT);

        Serial.println("No LED feedback.");
    }

    // Notify user that feedback setup is complete
    Serial.println("Feedback initialised succesfully");
    delay(2000);
}

// Function to provide LED feedback
void ledFeedback(bool state)
{
    if (state)
    {
        // if state is true, turn on green LED for a short duration
        digitalWrite(greenPin, HIGH); // Turn LED on
        delay(ledDelay);
    }
    else
    {

        // if state is false, turn off green LED
        digitalWrite(greenPin, LOW); // Turn LED off
    }
}

// Function to initialize the LCD for those who have one
void lcdInitialise()
{

    lcd.init(); // initialize the lcd
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("ECTDS PROBE");
    lcd.setCursor(0, 1);
    delay(2000);
}

// Function to print temperature on LCD
void lcdPrintTemp(float tempC)
{

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.setCursor(6, 0);
    lcd.print(tempC);
    lcd.setCursor(12, 0);
    lcd.print("C");
}

// Function to print conductance on LCD
void lcdPrintCond(float condmicroS)
{

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("EC:");
    lcd.setCursor(4, 1);
    lcd.print(condmicroS);
    lcd.setCursor(10, 1);
    lcd.print("μS");
}

// Functions to turn on individual LEDs

void redLED() // red LED
{
    digitalWrite(redPin, 1);
}

void orangeLED() // orange LED
{
    digitalWrite(orangePin, 1);
}

void greenLED() // green LED
{
    digitalWrite(greenPin, 1);
}