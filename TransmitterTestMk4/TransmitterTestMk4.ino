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

#define SwitchPin1 10  // Arcade switch is connected to Pin 10 on NANO
#define SwitchPin2 6
#define SwitchPin3 5
#define SwitchPin4 4
#define SwitchPin5 3

int SentMessage[5] = { 0, 0, 0, 0, 0 };  // Used to store value before being sent through the NRF24L01

RF24 radio(7, 8);  // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6;  // Needs to be the same for communicating between 2 NRF24L01


void setup() {
  Serial.begin(9600);
  pinMode(SwitchPin1, INPUT_PULLUP);  // Define the arcade switch NANO pin as an Input using Internal Pullups
  digitalWrite(SwitchPin1, HIGH);     // Set Pin to HIGH at beginning
  pinMode(SwitchPin2, INPUT_PULLUP);
  digitalWrite(SwitchPin2, HIGH);
  pinMode(SwitchPin3, INPUT_PULLUP);
  digitalWrite(SwitchPin3, HIGH);
  pinMode(SwitchPin4, INPUT_PULLUP);
  digitalWrite(SwitchPin4, HIGH);
  pinMode(SwitchPin5, INPUT_PULLUP);
  digitalWrite(SwitchPin5, HIGH);

  radio.begin();                // Start the NRF24L01
  radio.openWritingPipe(pipe);  // Get NRF24L01 ready to transmit
}

void loop(void) {

  if (digitalRead(SwitchPin1) == LOW) {  // If Switch is Activated
    SentMessage[0] = 1;
    Serial.write("Button 1 Pressed\n");
  } else {
    SentMessage[0] = 0;
  }
  if (digitalRead(SwitchPin2) == LOW) {
    SentMessage[1] = 1;
    Serial.write("Button 2 Pressed\n");
  } else {
    SentMessage[1] = 0;
  }
  if (digitalRead(SwitchPin3) == LOW) {
    SentMessage[2] = 1;
    Serial.write("Button 3 Pressed\n");
  } else {
    SentMessage[2] = 0;
  }
  if (digitalRead(SwitchPin4) == LOW) {
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

  radio.write(SentMessage, sizeof(SentMessage));  // Send value through NRF24L01
}