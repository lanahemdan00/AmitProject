/*
 * TIMER.c
 *
 * Created: 15/12/2021 10:49:29 PM
 *  Author: lana
 */ 


#include "TIMER.h"

void timer1_init(void)
{
	

	set_bit(TCCR1B,WGM12);
	
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	/*
	OCR1BH = 0b00000011;
	OCR1BL = 0b11010001;
	*/
	set_bit(TCCR1B,CS10);
	clr_bit(TCCR1B,CS11);
	set_bit(TCCR1B,CS12);
	sei();

}

void timer0_init(void)
{
	set_bit(TCCR0,WGM01);
	OCR0 = 250;
	set_bit(TCCR0,CS00);
	set_bit(TCCR0,CS02);
	sei();
	set_bit(TIMSK,OCIE0);
	
}

void timer1_INT_disable(void){
	clr_bit(TIMSK,OCIE1A);
	//clr_bit(TIMSK,OCIE1B);
}

void timer1_INT_enable(void){
	set_bit(TIMSK,OCIE1A);
	//set_bit(TIMSK,OCIE1B);
}