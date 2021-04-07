/*	Author: bshah016
 *  Partner(s) Name: Brij Shah
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k) { //all credit for this function goes to zyBooks, given in one of the exercises
	return ((x & (0x01 << k )) != 0);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //initializes port A and B
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;//' ' but sets to 0
    /* Insert your solution below */
	unsigned char tmpA;
	unsigned char tmpB;
	unsigned char count = 0; //counter for number of 1s

    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	count = 0; //need to reset otherwise will keep increasing
	
	for (unsigned char i = 0; i < 8; ++i) { //will go for the 8 bits of the input
		//if (((tmpA >> i) & 0x01) == 0x01) { 
		/*
		if statement above would shift tmpA, & with 0000 0001 and check if result is 0000 00001,
		meaning bit of interest is a 1
		*/
		if (GetBit(tmpA, i) == 0x01) { //checks if bit of interest is 1
			count++; //increments counter
		}
		//if (((tmpB >> i) & 0x01) == 0x01) { //if statement does same as the tmpA one
		if (GetBit(tmpB, i) == 0x01) {	//does same as above
			count++; //same as above
		}
	}
	PORTC = count; //set PORTC to the # of 1s (counter)
    }
    return 1;
}
