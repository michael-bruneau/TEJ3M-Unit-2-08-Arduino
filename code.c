/*
  Created by: Michael Bruneau
  Created on: April 2025

  This Arduino program causes a micro servo to spin 180 degrees when potentiometer resistance is 1MΩ and 0 degrees at 0Ω
*/

#include <Servo.h>

Servo servoNumber1;

// variables & constants
const int MICRO_SERVO_SIGNAL_PIN = 8;
const int POTENTIOMETER_WIPER_PIN = A1;
const int MAX_ANALOG_OUTPUT = 1023;
const float UNIT_ANGLE = 0.17;
int wiperOutput = 0;
int blinkDelay = 1000;
int angle = 0;

void setup() {
  // Setups pins
  pinMode(POTENTIOMETER_WIPER_PIN, INPUT);
  servoNumber1.attach(MICRO_SERVO_SIGNAL_PIN);
  servoNumber1.write(0);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  	// finds wiper output
  	wiperOutput = analogRead(POTENTIOMETER_WIPER_PIN);
  
  	// converts wiper output to angle
  	angle = UNIT_ANGLE * wiperOutput;
      
  	// Turns on LED if a object gets close to the sonar
    servoNumber1.write(angle);     
}
