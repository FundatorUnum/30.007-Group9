//Created by Yvan / https://Brainy-Bits.com
//This code is in the public domain...
//You can: copy it, use it, modify it, share it or just plain ignore it!
//Thx!
// NRF24L01 Module Tutorial - Code for Transmitter using Arduino NANO

//Include needed Libraries at beginning
#include "nRF24L01.h"  //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

int FsrPin1 = A0;  // the FSR and 10K pulldown are connected to a0
int fsrReading1;  // the analog reading from the FSR resistor divider

int FsrPin2 = A1;
int fsrReading2;

int FsrPin3 = A2;
int fsrReading3;

int FsrPin4 = A3;
int fsrReading4;

int FsrPin5 = A4;
int fsrReading5;



int SentMessageL[6] = { 0, 0, 0, 0, 0, 0 };  // Used to store value before being sent through the NRF24L01

RF24 radio(7, 8);  // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xA6A6A6A6A6A6;  // Needs to be the same for communicating between 2 NRF24L01

//int Array[1];

void setup() {
  Serial.begin(9600);           // establish serial communication
  radio.begin();                // Start the NRF24L01
  radio.openWritingPipe(pipe);  // Get NRF24L01 ready to transmit
}

void loop(void) {

  SentMessageL[0] = analogRead(FsrPin1);
  SentMessageL[1] = analogRead(FsrPin2);
  SentMessageL[2] = analogRead(FsrPin3);
  SentMessageL[3] = analogRead(FsrPin4);
  SentMessageL[4] = analogRead(FsrPin5);
  SentMessageL[5] = 1;
  
  radio.write(SentMessageL, sizeof(SentMessageL));  // Send value through NRF24L01
  Serial.println("Sending");
  delay(20);
}
