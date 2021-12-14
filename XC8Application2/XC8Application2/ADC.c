/*
 * ADC.c
 *
 * Created: 14/12/2021 6:13:19 PM
 *  Author: lana
 */ 
#include "ADC.h"


void ADC_INITIAL(){
	
	set_bit(ADMUX,REFS0);
	
	
	clr_bit(ADMUX,MUX0);
	clr_bit(ADMUX,MUX1);
	clr_bit(ADMUX,MUX2);
	clr_bit(ADMUX,MUX3);
	clr_bit(ADMUX,MUX4);
	
	
	clr_bit(ADMUX,ADLAR);
	set_bit(ADCSRA,ADPS0);
	clr_bit(ADCSRA,ADPS1);
	clr_bit(ADCSRA,ADPS2);
	set_bit(ADCSRA,ADEN);
	
}


uint16_t ADC_READ(){
	
	uint16_t VAL;
	set_bit(ADCSRA,ADSC);
	while(is_bit_clr(ADCSRA,ADIF));
	VAL = ADCL;
	VAL =VAL|(ADCH<<8);	
	set_bit(ADCSRA,ADIF); 
	return VAL;
	
}