/*
Created by Yvan / https://Brainy-Bits.com

This code is in the public domain...
You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!

*/

// NRF24L01 Module Tutorial - Code for Transmitter using Arduino NANO

//Include needed Libraries at beginning
#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

#define SwitchPin1 10 // Arcade switch is connected to Pin 10 on NANO
#define SwitchPin2 6
#define SwitchPin3 5
int SentMessage[1] = {000}; // Used to store value before being sent through the NRF24L01

RF24 radio(7,8); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 


void setup(){
Serial.begin(9600);
pinMode(SwitchPin1, INPUT_PULLUP); // Define the arcade switch NANO pin as an Input using Internal Pullups
digitalWrite(SwitchPin1,HIGH); // Set Pin to HIGH at beginning
pinMode(SwitchPin2, INPUT_PULLUP);
digitalWrite(SwitchPin2,HIGH);
pinMode(SwitchPin3, INPUT_PULLUP);
digitalWrite(SwitchPin3,HIGH);

radio.begin(); // Start the NRF24L01
radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
}

void loop(void){

if (digitalRead(SwitchPin1) == LOW){ // If Switch is Activated
SentMessage[0] = 001;
Serial.write("Button 1 Pressed\n");
radio.write(SentMessage, 1); // Send value through NRF24L01
} else if (digitalRead(SwitchPin2) == LOW){
SentMessage[0] = 010;
Serial.write("Button 2 Pressed\n");
radio.write(SentMessage, 1);
} else if (digitalRead(SwitchPin3) == LOW){
SentMessage[0] = 011;
Serial.write("Button 3 Pressed\n");
radio.write(SentMessage, 1);
}
else {
SentMessage[0] = 000;
radio.write(SentMessage, 1);
}
}
