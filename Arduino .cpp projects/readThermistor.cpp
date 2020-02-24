/*
Description: Read thermistor value and retrieve celsius value
*/
#include <Arduino.h>
#define ANALOG_PIN 0
#define TABLE_SIZE 32


//Create a struct for keeping float values of our lookup table
typedef struct {
	float x; // ADC value
	float y; // Celsius equivalent
} lookupTable;
void setup() {
  
}

lookupTable table[TABLE_SIZE] = {
	{250, 1.4},
	{275, 4.0},
	{300, 6.4},
	{325, 8.8},
	{350, 11.1},
	{375, 13.4},
	{400, 15.6},
	{425, 17.8},
	{450, 20.0},
	{475, 22.2},
	{500, 24.4},
	{525, 26.7},
	{550, 29.0},
	{575, 31.3},
	{600, 33.7},
	{625, 36.1},
	{650, 38.7},
	{675, 41.3},
	{700, 44.1},
	{725, 47.1},
	{750, 50.2},
	{775, 53.7},
	{784, 55.0},
	{825, 61.5},
	{850, 66.2},
	{875, 71.5},
	{900, 77.9},
	{925, 85.7},
	{937, 90.3},
	{950, 96.0},
	{975, 111.2},
	{1000, 139.5},
};


// Use linear interpolation to find a corresponding temperature value in Celsius for the ADC value outputted by the thermistor
float interpolate(lookupTable* table, float x, int tableSize) {

	//Loop through the lookup table
	for(int i = 0; i < tableSize - 1; i++)
	{
		//Look for 2 points between which the thermistor ADC value goes
		if (table[i].x <= x && table[i+1].x >= x)
		{
			//Use the slope formula to find the slope m
			float m1 = x - table[i].x;
			float m2 = table[i +1].x - table[i].x;
			float m = m1 / m2;
			
			return table[i].y + (table[i+1].y - table[i].y) * m;
		}
	}
	return 0; // For ADC values outside the lookup table range
}

void loop() {
	//ADC value
	float adcReading = analogRead(ANALOG_PIN);
	volatile float celcius = interpolate(table, adcReading, TABLE_SIZE);

	
}