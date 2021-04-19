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
unsigned char tmpC = 0x00;
enum SM1_STATES { SM1_SMStart, SM1_Start, SM1_Inc, SM1_Dec, SM1_Rst, SM1_Wait} SM1_STATE;
void Tick_LoHi() { 
   switch(SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_Start;
         }
         break;
      case SM1_Start:
         if (PINA == 0x03) {
            SM1_STATE = SM1_Rst;
         }
         else if ((PINA == 0x02)&&(tmpC!=0)) {
            SM1_STATE = SM1_Dec;
         }
         else if ((PINA == 0x01) &&(tmpC!=9)) {
            SM1_STATE = SM1_Inc;
         }
         else {
            SM1_STATE = SM1_Start;
         }
         break;
      case SM1_Inc:
         if (1) {
            SM1_STATE = SM1_Wait;
         }
         break;
      case SM1_Dec:
         if (1) {
            SM1_STATE = SM1_Wait;
         }
         break;
      case SM1_Rst:
         if (1) {
            SM1_STATE = SM1_Start;
         }
         break;
      case SM1_Wait:
         if (PINA == 0x03) {
            SM1_STATE = SM1_Rst;
         }
         else if (PINA == 0x00) {
            SM1_STATE = SM1_Start;
         }
         else if ((PINA == 0x01)||(PINA == 0x02)) {
            SM1_STATE = SM1_Wait;
         }
         else {
            SM1_STATE = SM1_Wait;
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
         tmpC = PORTC;
         break;
      case SM1_Inc:
         tmpC = tmpC +1;
PORTC = tmpC;
         break;
      case SM1_Dec:
         tmpC = tmpC -1;
PORTC = tmpC;
         break;
      case SM1_Rst:
         tmpC = 0;
PORTC = tmpC;
         break;
      case SM1_Wait:
         
         break;
   }
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA=0x00; PORTA=0x00;
	DDRC=0xFF; PORTC =0x07;
	SM1_STATE = SM1_SMStart;
    /* Insert your solution below */
    while (1) {
	Tick_LoHi();
    }
    return 1;
}
