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

enum SM1_STATES { SM1_SMStart, SM1_Start, SM1_Wait1, SM1_B1, SM1_Wait2, SM1_B0} SM1_STATE;
void Tick_LoHi() { 
   switch(SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_Start;
         }
         break;
      case SM1_Start:
         if (1) {
            SM1_STATE = SM1_Wait1;
         }
         break;
      case SM1_Wait1:
         if (!(PINA == 0x01)) {
            SM1_STATE = SM1_Wait1;
         }
         else if (PINA == 0x01) {
            SM1_STATE = SM1_B1;
         }
         else {
            SM1_STATE = SM1_Wait1;
         }
         break;
      case SM1_B1:
         if (PINA == 0x01) {
            SM1_STATE = SM1_B1;
         }
         else if (!(PINA == 0x01)) {
            SM1_STATE = SM1_Wait2;
         }
         else {
            SM1_STATE = SM1_B1;
         }
         break;
      case SM1_Wait2:
         if (!(PINA == 0x01)) {
            SM1_STATE = SM1_Wait2;
         }
         else if (PINA == 0x01) {
            SM1_STATE = SM1_B0;
         }
         else {
            SM1_STATE = SM1_Wait2;
         }
         break;
      case SM1_B0:
         if (PINA == 0x01) {
            SM1_STATE = SM1_B0;
         }
         else if (!(PINA == 0x01)) {
            SM1_STATE = SM1_Wait1;
         }
         else {
            SM1_STATE = SM1_B0;
         }
         break;
      default:
         SM1_STATE = SM1_Start;
         break;
   }
   switch(SM1_STATE) { 
      case SM1_SMStart:
         
         break;
      case SM1_Start:
		   PORTB = 0x01;
         break;
      case SM1_Wait1:
         break;
      case SM1_B1:
 		PORTB = 0x02;
         break;
      case SM1_Wait2:
  
         break;
      case SM1_B0:
	 PORTB = 0x01;
         break;
   }
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0x00;
	DDRB = 0xFF;	PORTB = 0x00;
    /* Insert your solution below */
	SM1_STATE = SM1_SMStart;		
    while (1) {
	Tick_LoHi();
    }
    return 1;
}
