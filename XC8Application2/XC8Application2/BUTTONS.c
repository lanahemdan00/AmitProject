/*
 * BUTTONS.c
 *
 * Created: 14/12/2021 6:27:36 PM
 *  Author: lana
 */ 


#include "BUTTONS.h"
void BUTTONS_INIT(void){
	clr_bit(DDRB,ON_OFF_PIN);
	clr_bit(DDRB,UP_PIN);
	clr_bit(DDRB,DOWN_PIN);
	set_bit(PORTB,ON_OFF_PIN);
	set_bit(PORTB,UP_PIN);
	set_bit(PORTB,DOWN_PIN);
	sei();
	set_bit(MCUCSR,ISC2);
	set_bit(GICR,INT2);
}



unsigned char UP_PRESS(void){

	if(!(read_bit(PINB,UP_PIN))){
		
		_delay_ms(100);
		
		if (!(read_bit(PINB,UP_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}



unsigned char DOWN_PRESS(void){

	if(!(read_bit(PINB,DOWN_PIN))){
		
		_delay_ms(100);
		

		if (!(read_bit(PINB,DOWN_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}