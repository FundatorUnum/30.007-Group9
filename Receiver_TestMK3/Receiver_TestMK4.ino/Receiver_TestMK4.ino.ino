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

int ReceivedMessage[5] = {0,0,0,0,0}; // Used to store value received by the NRF24L01

RF24 radio(7,8); // NRF24L01 used SPI pins + Pin 7 and 8 on the UNO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 


void setup(void){
Serial.begin(9600);
radio.begin(); // Start the NRF24L01

radio.openReadingPipe(0,pipe); // Get NRF24L01 ready to receive

radio.startListening(); // Listen to see if information received

pinMode(LED_PIN1, OUTPUT); // Set RGB Stick UNO pin to an OUTPUT
pinMode(LED_PIN2, OUTPUT);
pinMode(LED_PIN3, OUTPUT);
//pinMode(LED_PIN4, OUTPUT); (not needed because we're using serial monitor to test)
//pinMode(LED_PIN5, OUTPUT); (not needed because we're using serial monitor to test)


digitalWrite(LED_PIN1, LOW);
digitalWrite(LED_PIN2, LOW);
digitalWrite(LED_PIN3, LOW);
//digitalWrite(LED_PIN4, LOW); (not needed because we're using serial monitor to test)
//digitalWrite(LED_PIN5, LOW); (not needed because we're using serial monitor to test)
}
void loop(void){

while (radio.available())
{

radio.read(ReceivedMessage, sizeof(ReceivedMessage)); // Read information from the NRF24L01

//Serial.write(ReceivedMessage[0]);

if (ReceivedMessage[0] == 1) // Indicates switch is pressed
{
digitalWrite(LED_PIN1, HIGH);
Serial.write("LED 1 is ON\n");
}
else
{
digitalWrite(LED_PIN1, LOW);
}
if (ReceivedMessage[1] == 1) // Indicates switch is pressed
{
digitalWrite(LED_PIN2, HIGH);
Serial.write("LED 2 is ON\n");
}
else
{
digitalWrite(LED_PIN2, LOW);
}
if (ReceivedMessage[2] == 1) // Indicates switch is pressed
{
digitalWrite(LED_PIN3, HIGH);
Serial.write("LED 3 is ON\n");
}
else
{
digitalWrite(LED_PIN3, LOW);
}
if (ReceivedMessage[3] == 1) // Indicates switch is pressed
{
//digitalWrite(LED_PIN4, HIGH);
Serial.write("LED 4 is ON\n");
}
else
{
//digitalWrite(LED_PIN4, LOW);
}
if (ReceivedMessage[4] == 1) // Indicates switch is pressed
{
//digitalWrite(LED_PIN5, HIGH);
Serial.write("LED 5 is ON\n");
}
else
{
//digitalWrite(LED_PIN5, LOW);
}
delay(10);
}
}
