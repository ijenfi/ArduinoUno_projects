/*
Description: blinking a 7seg display
*/
#include <Arduino.h>
#include "includedFile.h"
#define LED_A 2
#define LED_B 8
#define LED_C 6
#define LED_D 5
#define LED_E 4
#define LED_F 3
#define LED_G 7

void blink3E();
void counterClock();
void onOff();
void clockWiseCircle();

void setup() {
  pinMode(LED_A, OUTPUT); 
  pinMode(LED_F, OUTPUT); 
  pinMode(LED_E, OUTPUT); 
  pinMode(LED_D, OUTPUT); 
  pinMode(LED_C, OUTPUT); 
  pinMode(LED_G, OUTPUT); 
  pinMode(LED_B, OUTPUT); 
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_F, HIGH);
  digitalWrite(LED_E, HIGH);
  digitalWrite(LED_D, HIGH);
  digitalWrite(LED_C, HIGH);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, HIGH);

}

void loop() {

//LIGHTING 3 & E
	blink3E();
	
//Counter clockwise
	counterClock();
	 
// On & OFF	
	onOff();

//clockwise circle 3 times abcdef
	clockWiseCircle();
}

void blink3E(){
	//light 3
	for(int i=1; i<4; i++ ){

		digitalWrite(LED_A, LOW);//a
		digitalWrite(LED_B, LOW);//b
		digitalWrite(LED_G, LOW);//g
		digitalWrite(LED_C, LOW);//c
		digitalWrite(LED_D, LOW);//d
		delay(500);
		digitalWrite(LED_A, HIGH);
		digitalWrite(LED_B, HIGH);
		digitalWrite(LED_G, HIGH);
		digitalWrite(LED_C, HIGH);
		digitalWrite(LED_D, HIGH);
		delay(500);

		//light E
		digitalWrite(LED_A, LOW);
		digitalWrite(LED_F, LOW);
		digitalWrite(LED_G, LOW);
		digitalWrite(LED_E, LOW);
		digitalWrite(LED_D, LOW);
		delay(500);
		digitalWrite(LED_A, HIGH);
		digitalWrite(LED_F, HIGH);
		digitalWrite(LED_G, HIGH);
		digitalWrite(LED_E, HIGH);
		digitalWrite(LED_D, HIGH);
		delay(500);
	}
}

void counterClock(){
for(int i=1; i<4; i++)
{

	digitalWrite(LED_A, LOW);
	delay(250);

	digitalWrite(LED_F, LOW);
	delay(250);

	digitalWrite(LED_E, LOW);
	delay(250);

	digitalWrite(LED_D, LOW);
	delay(250);

	digitalWrite(LED_C, LOW);
	delay(250);

	digitalWrite(LED_B, LOW);
	delay(250);

	digitalWrite(LED_A, HIGH);
	digitalWrite(LED_F, HIGH);
	digitalWrite(LED_E, HIGH);
	digitalWrite(LED_D, HIGH);
	digitalWrite(LED_C, HIGH);
	digitalWrite(LED_B, HIGH);
	}

}
void onOff(){
	for(int i = 1; i < 4; i ++)
	{
		for (int j = 2; j < 9; j++) //all the LEDs are on 
		{
			digitalWrite(j, LOW);
		}
		delay(500);
		for (int k = 2; k < 9; k++) //LEDs go off one by one with 500us delay
		{
			digitalWrite(k, HIGH);
			delay(500);
		}
	}
}
void clockWiseCircle(){
	int pinCount = 6; //length of array 
	int ledPins[] = {2, 8, 6, 5, 4, 3}; //LEDs array

	for (int i = 1; i < 4; i++)
	{
		for (int pin = 0; pin < pinCount; pin++) //Turns LEDs on one by one with 500us delay in between
		{
			digitalWrite(ledPins[pin], LOW);
			delay(500);
		}
		for (int pin = 0; pin < pinCount; pin++) //Turns LEDs off all once
		{
			digitalWrite(ledPins[pin], HIGH);
		}
	}


}