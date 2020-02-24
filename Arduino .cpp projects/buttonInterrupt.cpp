
#include <Arduino.h>
const int button = 2;
const int ledgreen = 11;
const int ledred = 13;

int buttonState = 0;
int buttoncount = 0;


void setup()
{
	pinMode(button, INPUT_PULLUP);
	pinMode(ledgreen, OUTPUT);
	pinMode(ledred, OUTPUT);
}

void loop()
{
	buttonState = digitalRead(button);
	if (buttonState == HIGH)
	{
		buttoncount++;
	}
	if (buttoncount == 1)
	{
		digitalWrite(ledgreen, HIGH);
		delay(3000);
		digitalWrite(ledgreen, LOW);
	}
	if (buttoncount == 2)
	{
		digitalWrite(ledred, HIGH);
		delay(3000);
		digitalWrite(ledred, LOW);
		buttoncount = 0;
	}
	else
	{
		digitalWrite(ledred, LOW);
		digitalWrite(ledgreen, LOW);
	}
}


