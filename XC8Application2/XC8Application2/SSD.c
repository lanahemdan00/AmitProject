/*
 * SSD.c
 *
 * Created: 14/12/2021 7:54:14 PM
 *  Author: lana
 */ 

#include "SSD.h"

uint8_t numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SSD_INITIAL(void){
	
	DDRD = 0xFF;
	set_bit(DDRB,6);
	set_bit(DDRB,7);
	SSD_DISAB();
	
}

void SSD_NUM(uint16_t N){
	PORTD = numbers[N];
}


void SSD_ENAB(uint8_t disp){
	if(disp == 1){
		set_bit(PORTB,6);
		clr_bit(PORTB,7);
	}
	else if (disp == 2){
		set_bit(PORTB,7);
		clr_bit(PORTB,6);
	}
}

void SSD_DISAB(void){
	clr_bit(PORTB,6);
	clr_bit(PORTB,7);
}

void SSD_OFF(void){
	PORTD = 0x00;
}

void SSD_WRITE(uint16_t N){
	uint8_t units;
	uint8_t tens;
	
	units = N % 10;
	tens = (int) N / 10;
	
	SSD_ENAB(DISP1);
	SSD_NUM(units);
	_delay_ms(5);
	
	SSD_ENAB(DISP2);
	SSD_NUM(tens);
	_delay_ms(5);
}