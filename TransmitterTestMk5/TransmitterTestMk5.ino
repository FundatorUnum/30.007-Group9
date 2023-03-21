/*
Created by Yvan / https://Brainy-Bits.com

This code is in the public domain...
You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!

*/

// NRF24L01 Module Tutorial - Code for Transmitter using Arduino NANO

//Include needed Libraries at beginning
#include "nRF24L01.h"  //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

int fsrPin = 0;  // the FSR and 10K pulldown are connected to a0
int fsrReading;  // the analog reading from the FSR resistor divider

#define SwitchPin1 A0  // Arcade switch is connected to Pin 10 on NANO
#define SwitchPin2 A1
#define SwitchPin3 A2
#define SwitchPin4 A3
#define SwitchPin5 A4

int SentMessage[5] = { fsr0, 0, 0, 0, 0 };  // Used to store value before being sent through the NRF24L01

RF24 radio(7, 8);  // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6;  // Needs to be the same for communicating between 2 NRF24L01


void setup() {
  Serial.begin(9600);
  radio.begin();                // Start the NRF24L01
  radio.openWritingPipe(pipe);  // Get NRF24L01 ready to transmit
}

void loop(void) {

  if (analogRead(SwitchPin1) == LOW) {  // If Switch is Activated
    SentMessage[0] = 1;
    Serial.write("Button 1 Pressed\n");
  } else {
    SentMessage[0] = 0;
  }
  if (analogRead(SwitchPin2) == LOW) {
    SentMessage[1] = 1;
    Serial.write("Button 2 Pressed\n");
  } else {
    SentMessage[1] = 0;
  }
  if (analogRead(SwitchPin3) == LOW) {
    SentMessage[2] = 1;
    Serial.write("Button 3 Pressed\n");
  } else {
    SentMessage[2] = 0;
  }
  if (analogRead(SwitchPin4) == LOW) {
    SentMessage[3] = 1;
    Serial.write("Button 4 Pressed\n");
  } else {
    SentMessage[3] = 0;
  }
  if (digitalRead(SwitchPin5) == LOW) {
    SentMessage[4] = 1;
    Serial.write("Button 5 Pressed\n");
  } else {
    SentMessage[4] = 0;
  }
  fsr0 = analogRead(fsrPin);

  Serial.print("Analog reading = ");
  Serial.print(fsrReading);  // print the raw analog reading

  if (fsrReading < 10) {
    Serial.println(" - No pressure");
  } else if (fsrReading < 200) {
    Serial.println(" - Light touch");
  } else if (fsrReading < 500) {
    Serial.println(" - Light squeeze");
  } else if (fsrReading < 800) {
    Serial.println(" - Medium squeeze");
  } else {
    Serial.println(" - Big squeeze");
  }
  delay(1000);

  radio.write(SentMessage, sizeof(SentMessage));  // Send value through NRF24L01
}