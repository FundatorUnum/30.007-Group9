/* 
Created by Yvan / https://Brainy-Bits.com

This code is in the public domain...
You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!

*/


// NRF24L01 Module Tutorial - Code for Receiver using Arduino UNO

//Include needed Libraries at beginning
#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

#define LED_PIN1 5 // Digital In (DI) of RGB Stick connected to pin 5 of the UNO
#define LED_PIN2 4
#define LED_PIN3 3
//#define LED_PIN4 (number) (not needed because we're using serial monitor to test)
//#define LED_PIN5 (number) (not needed because we're using serial monitor to test)

int ReceivedMessage[6] = {0,0,0,0,0,0}; // Used to store value received by the NRF24L01
int ReceivedMessageL[6] = {0,0,0,0,0,0}; // Store value receieved from the other NRF24L01

RF24 radio(7,8); // NRF24L01 used SPI pins + Pin 7 and 8 on the UNO

const uint64_t pipe1 = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 
const uint64_t pipe2 = 0xA6A6A6A6A6A6;

void setup(void){
Serial.begin(9600);
radio.begin(); // Start the NRF24L01

radio.openReadingPipe(0,pipe1); // Get NRF24L01 ready to receive
radio.openReadingPipe(1,pipe2);

radio.startListening(); // Listen to see if information received

//pinMode(LED_PIN1, OUTPUT); // Set RGB Stick UNO pin to an OUTPUT
//pinMode(LED_PIN2, OUTPUT);
//pinMode(LED_PIN3, OUTPUT);
//pinMode(LED_PIN4, OUTPUT); (not needed because we're using serial monitor to test)
//pinMode(LED_PIN5, OUTPUT); (not needed because we're using serial monitor to test)


//digitalWrite(LED_PIN1, LOW);
//digitalWrite(LED_PIN2, LOW);
//digitalWrite(LED_PIN3, LOW);
//digitalWrite(LED_PIN4, LOW); (not needed because we're using serial monitor to test)
//digitalWrite(LED_PIN5, LOW); (not needed because we're using serial monitor to test)
}
void loop(void){

while (radio.available(0))
{
  
int SoundInstructions[10] = {0,0,0,0,0,0,0,0,0,0};
int x = 0;
int y = 0;

radio.read(ReceivedMessage, sizeof(ReceivedMessage)); // Read information from the NRF24L01
if (ReceivedMessage[5] == 0){
  while (x < 5){
  SoundInstructions[x] = ReceivedMessage[x];
  x = x+1;
}
}

radio.read(ReceivedMessageL, sizeof(ReceivedMessageL));
if (ReceivedMessageL[5] == 1){
  while (y < 5){
  SoundInstructions[y+5] = ReceivedMessageL[y];
  y = y+1;
}
}


//int z = 0;
//while (z < 10){
//  Serial.print(SoundInstructions[z]);
//  Serial.print("  ");
//  z = z + 1;
//}
//Serial.print("\n");

//Right Hand
if (SoundInstructions[0] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[0] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[0] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[0] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
if (SoundInstructions[1] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[1] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[1] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[1] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
if (SoundInstructions[2] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[2] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[2] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[2] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
if (SoundInstructions[3] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[3] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[3] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[3] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
if (SoundInstructions[4] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[4] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[4] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[4] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
//Left Hand
if (SoundInstructions[5] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[5] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[5] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[5] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
if (SoundInstructions[6] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[6] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[6] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[6] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
if (SoundInstructions[7] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[7] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[7] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[7] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
if (SoundInstructions[8] < 10) {
    Serial.print("0, ");
  } else if (SoundInstructions[8] < 200) {
    Serial.print("1, ");
  } else if (SoundInstructions[8] < 500) {
    Serial.print("2, ");
  } else if (SoundInstructions[8] < 800) {
    Serial.print("3, ");
  } else {
    Serial.print("4, ");
  }
if (SoundInstructions[9] < 10) {
    Serial.println("0");
  } else if (SoundInstructions[9] < 200) {
    Serial.println("1");
  } else if (SoundInstructions[9] < 500) {
    Serial.println("2");
  } else if (SoundInstructions[9] < 800) {
    Serial.println("3");
  } else {
    Serial.println("4");
  }
}
}
