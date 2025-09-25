#include <userFeedback.h>

#include <Arduino.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
// LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

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

void setupUserFeedback()
{
    Serial.println("------------------------------------");
    Serial.println("Setup User Feedback");
    Serial.println("Enter '1' for LED feedback, '0' for no feedback:");
    while (Serial.available() == 0)
    {
        // wait for user input
    }
    char input = Serial.read();
    if (input == '1')
    {
        Serial.println("LED feedback enabled.");
        ledSequence();
    }
    else
    {
        Serial.println("No LED feedback.");
    }
    Serial.println("Feedback initialised succesfully");
    delay(2000);
}

void ledFeedback(bool state)
{
    if (state)
    {
        digitalWrite(greenPin, HIGH); // Turn LED on
        delay(ledDelay);
    }
    else
    {
        digitalWrite(greenPin, LOW); // Turn LED off
    }
}

void lcdInitialise()
{

    lcd.init(); // initialize the lcd
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("ECTDS PROBE");
    lcd.setCursor(0, 1);
    delay(2000);
}

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
void redLED()
{
    digitalWrite(redPin, 1);
}

void orangeLED()
{
    digitalWrite(orangePin, 1);
}

void greenLED()
{
    digitalWrite(greenPin, 1);
}