/*
 * EEPROM.c
 *
 * Created: 14/12/2021 7:49:21 PM
 *  Author: lana
 */ 

#include "EEPROM.h"

unsigned char EEPROM_READ(const unsigned short addr){
	EEARL = (unsigned char)addr;
	EEARH = (unsigned char)(addr>>8);
	
	set_bit(EECR,EERE);
	
	return EEDR;
}


void EEPROM_WRITE(const unsigned short addr, unsigned char data){
	unsigned char INT_EN=0;
	EEARL = (unsigned char)addr;
	EEARH = (unsigned char)(addr>>8);
	EEDR = data;	
	if(((SREG&(1<<7))>>7)==1){
		INT_EN = 1;
		clr_bit(SREG,7);
	}
	set_bit(EECR,EEMWE);
	set_bit(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	if (INT_EN==1)
	{
		set_bit(SREG,7);
	}
	
}