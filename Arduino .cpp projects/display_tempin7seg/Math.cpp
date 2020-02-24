/*
Description: Check LSB of two's complement of voltage
*/

#include <Arduino.h>
bool checkBit(int voltage) {
	//16 bit binary
	char binaryNumber[] = "0000000000000000";

	for(int position = 15; position >= 0; --position) {
		if (voltage % 2) {
			binaryNumber[position] = '1';
		}
		voltage = voltage / 2;
	}
	//Invert
	for(int i = 0; i <= 15; i++) {
		if (binaryNumber[i] == '0') {
			binaryNumber[i] = '1';
		}
		else {
			binaryNumber[i] = '0';
		}
	}
	char lastSignificantBit = '\0';
	bool lsb = true;
	// Since we only care about the LSB of our final result, we can do this:
	if (binaryNumber[15] == '0') {
		// "LSB after adding 1"
		lastSignificantBit = '1';
	}
	else {
		lastSignificantBit = '0';
		lsb = false;
	}

	return lsb;

}
