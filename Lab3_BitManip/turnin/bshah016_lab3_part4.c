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

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char level = 0;
	unsigned char tmpA;
	unsigned char tmp2;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA & 0x0F; //ensures the first 4 bits are 1, assuming that there are at least 4 bars
	tmp2 = PINA & 0xF0; //ensures the last 3 bits we need are 1s, where they need to be
	
	if (tmpA == 0x00) { //first case, where fuel level 0
		level = 0x40; //level = 0100 0000 (min fuel level)
	}
	if ((tmpA == 0x01) || (tmpA == 0x02)) { //second case fuel level is 0 or 1
		level = 0x60; //level = 0110 0000
	}
	if ((tmpA == 0x03) || (tmpA == 0x04)) { //third case where fuel level 3 or 4
		level = 0x70; //level = 0111 0000
	}
	if ((tmpA == 0x05) || (tmpA == 0x06)) { //fourth case where fuel level is 5 or 6
		level = 0x38; //level = 0011 1000
	}
	if ((tmpA == 0x07) || (tmpA == 0x08) || (tmpA == 0x09)) { //fifth case where fuel level is 7 or 8 or 9
		level = 0x3C; //level = 0011 1100
	}
	if ((tmpA == 0x0A) || (tmpA == 0x0B) || (tmpA == 0x0C)) { //sixth case where fuel level is 10 11 or 12
		level = 0x3E; //level = 0011 1110
	}
	if ((tmpA == 0x0D) || (tmpA == 0x0E) || (tmpA == 0x0F)) {
		level = 0x3F; //level = 0011 1111 (max fuel level)
	}
 	
	/*
 	0  0  0  0    0  0  0  0
	7  6  5  4    3  2  1  0

	for the icon to be there, must be (PA6 = 0, PA5 = 1, PA4 = 1)	
	0  0  1  1    0  0  0  0
	7  6  5  4    3  2  1  0

	that binary number above in hex is 0x30!
 	*/
	if (tmp2 == 0x30) { //if it is 0011 0000 (key in ignition (PA4 = 1), seated (PA5 = 1), no seatbelt (PA6 = 0))
		level = level | 0x80; //becomes 1xxx xxxx (because using |, other bits should not change since | with 0) 
	}	
	PORTC = level;
      }
    return 1;
}
