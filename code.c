/*
  Created by: Michael Bruneau
  Created on: March 2025

  This Arduio program causes micro Servo to to turn back and forth from 180 degress to 0 degrees
*/

#include <Servo.h>

Servo servoNumber1;

// variables & constants
const int MICRO_SERVO_SIGNAL_PIN = 8;
int wiperOutput = 0;
const int POTENTIOMETER_WIPER_PIN = A1;
int blinkDelay = 1000;
const int MAX_ANALOG_OUTPUT = 1023;
int angle = 0;
const float UNIT_ANGLE = 0.17;

void setup()
{
  // Setups pins
  pinMode(POTENTIOMETER_WIPER_PIN, INPUT);
  servoNumber1.attach(MICRO_SERVO_SIGNAL_PIN);
  servoNumber1.write(0);
  Serial.begin(9600); // Starts the serial communication
}


void loop() {
  	// finds wiper output
  	wiperOutput = analogRead(POTENTIOMETER_WIPER_PIN);
      
    // prints
    //Serial.print("Resitance is ");
  	//Serial.println(resitanceValue);
  	Serial.print(UNIT_ANGLE);
  
  	// converts to angle
  	angle = UNIT_ANGLE * wiperOutput;
      
  	// Turns on LED if a object gets close to the sonar
    servoNumber1.write(angle);     
}
