#ifndef userFeedback_h
#define userFeedback_h

int ledDelay = 1000;
//#include <Arduino.h>

#define greenPin 13
#define redPin 12
#define orangePin 11

void ledSequence(){
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

void setupUserFeedback() {
    Serial.println("------------------------------------");
    Serial.println("Setup User Feedback");
    Serial.println("Enter '1' for LED feedback, '0' for no feedback:");
    while (Serial.available() == 0) {
        // wait for user input
    }
    char input = Serial.read();
    if (input == '1') {
        Serial.println("LED feedback enabled.");
        ledSequence();
    } else {
        Serial.println("No LED feedback.");
    }
    Serial.println("Feedback initialised succesfully");
    delay(2000);
}

void ledFeedback(bool state) {
    
    if (state) {
        digitalWrite(greenPin, HIGH); // Turn LED on
        delay(ledDelay);
    } else {
        digitalWrite(greenPin, LOW);  // Turn LED off
    }
}

void redLED(){
    digitalWrite(redPin, 1);
}

void orangeLED(){
    digitalWrite(orangePin, 1);
}

void greenLED(){
    digitalWrite(greenPin, 1);
}

#endif