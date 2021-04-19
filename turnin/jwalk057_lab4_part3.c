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
enum SM1_STATES { SM1_SMStart, SM1_Fail, SM1_Lock, SM1_s0, SM1_wait, SM1_Unlock} SM1_STATE;
void Tick_LoHi() { 
   switch(SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_s0;
         }
         break;
      case SM1_Fail:
         if (PINA == 0x80) {
            SM1_STATE = SM1_Lock;
         }
         else if (1) {
            SM1_STATE = SM1_s0;
         }
         break;
      case SM1_Lock:
 
            SM1_STATE = SM1_s0;
         
         break;
      case SM1_s0:
         if (PINA == 0x04) {
            SM1_STATE = SM1_wait;
         }
         else if (PINA == 0x80) {
            SM1_STATE = SM1_Lock;
         }
         else if ((!(PINA == 0x04))&&(PINA == 0x00)) {
            SM1_STATE = SM1_Fail;
         }
         else if ((!(PINA == 0x04))&&(PINA == 0x02)) {
            SM1_STATE = SM1_Fail;
         }
         else {
            SM1_STATE = SM1_s0;
         }
         break;
      case SM1_wait:
         if (PINA == 0x80) {
            SM1_STATE = SM1_Lock;
         }
         else if (PINA == 0x02) {
            SM1_STATE = SM1_Unlock;
         }
         else if (!(PINA == 0x02)&&(PINA == 0x00)) {
            SM1_STATE = SM1_Fail;
         }
         else if (!(PINA == 0x02)&&(PINA == 0x04)) {
            SM1_STATE = SM1_Fail;
         }
         else {
            SM1_STATE = SM1_wait;
         }
         break;
      case SM1_Unlock:
         if (PINA == 0x80) {
            SM1_STATE = SM1_Lock;
         }
         else {
            SM1_STATE = SM1_Unlock;
         }
         break;
      default:
         SM1_STATE = SM1_s0;
         break;
   }
   switch(SM1_STATE) { 
      case SM1_SMStart:
         
         break;
      case SM1_Fail:
         
         break;
      case SM1_Lock:
         PORTB=0x00;
         break;
      case SM1_s0:
         
         break;
      case SM1_wait:
         
         break;
      case SM1_Unlock:
         PORTB=0x01;
         break;
   }
}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA=0x00; PORTA=0x00;
	DDRB=0xFF; PORTB =0x00;
	SM1_STATE = SM1_SMStart;
    /* Insert your solution below */
    while (1) {
	Tick_LoHi();
    }
    return 1;
}
