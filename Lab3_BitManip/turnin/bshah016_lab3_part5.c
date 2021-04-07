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
	//DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x03; PORTB = 0xFF;
	//DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0x00; PORTD = 0xFF;


	//unsigned char tmpA;
	unsigned char tmpB;
	unsigned char tmpB2;
	//unsigned char tmpC;
	unsigned char tmpD;
	unsigned short weight = 0;
    /* Insert your solution below */
    while (1) {
	
	tmpB = 0x00;
	tmpB2 = PINB;
	tmpD = PIND;
	weight = (tmpD << 1) + (tmpB2 & 0x01); //since fin is short, can hole 16 bits, so does not lose any bits when you shift a char, which is 8 bits. You then & tmpB2 with 0x01 in order to isolate the 0th bit, because that is all we care about
  	if (weight >= 70) { //if weight > 70
		tmpB = tmpB | 0x02; //ensures there is a 1 in the 2nd bit
	}
	if ((weight > 5) && (weight < 70)) {
		tmpB = tmpB | 0x04; //ensures there is a 1 in the 3rd bit
	}
	PORTB = tmpB;
	
    }
    return 1;
}
