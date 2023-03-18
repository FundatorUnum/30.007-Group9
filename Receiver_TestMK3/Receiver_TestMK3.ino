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
//#define LED_PIN4 (number)
//#define LED_PIN5 (number)
//
//int LT = 0;
//int LI = 0;
//int LM = 0;
//int LR = 0;
//int LP = 0;

int LEDCount = 5;
//int InArray[5] = {LT,LI,LM,LR,LP};
int ReceivedMessage[3] = {0,0,0}; // Used to store value received by the NRF24L01

RF24 radio(7,8); // NRF24L01 used SPI pins + Pin 7 and 8 on the UNO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 


void setup(void){
Serial.begin(9600);
radio.begin(); // Start the NRF24L01

radio.openReadingPipe(3,pipe); // Get NRF24L01 ready to receive

radio.startListening(); // Listen to see if information received

pinMode(LED_PIN1, OUTPUT); // Set RGB Stick UNO pin to an OUTPUT
pinMode(LED_PIN2, OUTPUT);
pinMode(LED_PIN3, OUTPUT);
//pinMode(LED_PIN4, OUTPUT);
//pinMode(LED_PIN5, OUTPUT);


digitalWrite(LED_PIN1, LOW);
digitalWrite(LED_PIN2, LOW);
digitalWrite(LED_PIN3, LOW);
//digitalWrite(LED_PIN4, LOW);
//digitalWrite(LED_PIN5, LOW);
}
void loop(void){

while (radio.available())
{

radio.read(ReceivedMessage, 1); // Read information from the NRF24L01
Serial.print(ReceivedMessage)


for (int thisLED = 0; thisLED < 3; thisLED++) { // Indicates switch is pressed
  digitalWrite(ReceivedMessage[thisLED], HIGH);
}

delay(10);
}
}
