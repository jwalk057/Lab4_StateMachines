/*	Author: lab
 *  Partner(s) Name: Jeremy Walker
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

enum SM {SM_Start, SM_WaitB0, SM_B1, SM_WaitB1} sm1;
        unsigned char tmpB =0x00;
        void Tick(){
                switch(sm1){
                        case SM_Start:
                                if(PINA & 0x01){sm1 = SM_Start;}
                                else{sm1 = SM_WaitB0;}
                                tmpB = 0x01;
                                PORTB = tmpB;
                                break;

                        case SM_WaitB0:
                                if(PINA & 0x01){sm1 = SM_B1;}
                                else{sm1 = SM_WaitB0;}
                                break;

                        case SM_B1:
                                if(PINA & 0x01){sm1 = SM_B1;}
                                else{sm1 = SM_WaitB1;}
                                tmpB = 0x02;
                                PORTB = tmpB;
                                break;

                        case SM_WaitB1:
                                if(PINA & 0x01){sm1 = SM_Start;}
                                else{sm1 = SM_WaitB0;}
				break;
                }

        }


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0x00;
	DDRB = 0xFF;	PORTB = 0x00;
    /* Insert your solution below */
	sm1 = SM_Start;		
    while (1) {
	Tick();
    }
    return 1;
}
