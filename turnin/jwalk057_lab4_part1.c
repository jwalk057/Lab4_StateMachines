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
         if (!A0) {
            SM1_STATE = SM1_Wait1;
         }
         else if (A0) {
            SM1_STATE = SM1_B1;
         }
         else {
            SM1_STATE = SM1_Wait1;
         }
         break;
      case SM1_B1:
         if (A0) {
            SM1_STATE = SM1_B1;
         }
         else if (!A0) {
            SM1_STATE = SM1_Wait2;
         }
         else {
            SM1_STATE = SM1_B1;
         }
         break;
      case SM1_Wait2:
         if (!A0) {
            SM1_STATE = SM1_Wait2;
         }
         else if (A0) {
            SM1_STATE = SM1_B0;
         }
         else {
            SM1_STATE = SM1_Wait2;
         }
         break;
      case SM1_B0:
         if (A0) {
            SM1_STATE = SM1_B0;
         }
         else if (!A0) {
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
         B0=1;
B1=0;
         break;
      case SM1_Wait1:
         
         break;
      case SM1_B1:
         B0=0;
B1=1;
         break;
      case SM1_Wait2:
         
         break;
      case SM1_B0:
         B0=1;
B1=0;
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
	Tick_LoHi();
    }
    return 1;
}
