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
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char upper = 0x00;
	unsigned char lower = 0x00;
    /* Insert your solution below */
    while (1) {
	upper = PINA;
	lower = PINA;
	/*
 	ok, so we need to figure out a way to swap the 2 nibbles
	1 0 1 0    0 1 0 1 
	7 6 5 4    3 2 1 0
	
	should become ..

	0 1 0 1    1 0 1 0 
	7 6 5 4    3 2 1 0


	if we have two temp variables set them to PINA, 
	shift each one 4 times, so it can get the two nibbles

	upper = upper >> 4; (would become 0000 1010)
	lower = lower << 4; (would become 0101 0000)

	
 	*/
	upper = upper >> 4;
	lower = lower >> 4;	

	PORTC = lower;
	PORTB = upper;
    }
    return 1;
}
