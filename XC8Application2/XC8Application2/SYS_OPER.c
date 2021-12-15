/*
 * SYS_OPER.c
 *
 * Created: 14/12/2021 8:40:57 PM
 *  Author: lana
 */ 

#include "SYS_OPER.h"

void SYS_INITIAL(void){
	
	ADC_INITIAL();
	BUTTONS_INIT();
	SSD_INITIAL();
	set_bit(DDRB,0);//LED
	clr_bit(PORTB,0);//LED
	set_bit(DDRB,5);//COOL
	set_bit(DDRB,4);//HEAT
	timer0_init();
	timer1_init();
	timer1_INT_enable();
	Curr_state = OFF;
	
	
	if(EEPROM_READ(0x0000) != 0xFF){
		desired_temp = EEPROM_READ(0x0000);
	}
	else{
		desired_temp = 50;
	}
	TEMP_INITIAL();
	EEPROM_WRITE(0x0000,(uint8_t) desired_temp);
	
}

void OFF_STATE(void){
	SSD_OFF();
	clr_bit(PORTB,0);
	clr_bit(PORTB,4);
	clr_bit(PORTB,5);
	SLEEP();
}

void ON_STATE(void){
	
	if (temp_measure_f == 1){
		actual_temp = (ADC_READ()*0.5);
		NEW_TEMP(temp_arr , actual_temp);
		avg_temp = AVG_TEMP(temp_arr);
		temp_measure_f = 0;
	}
	
	SSD_WRITE(actual_temp);
	
	CHAGE_TEMP();
	
	if(UP_PRESS()==PRESSED || DOWN_PRESS()==PRESSED){

		SSD_DISAB();
		setting_counter = 0;
		Curr_state = SETTING;
		
	}
}


void SET_STATE(void){
	clr_bit(PORTB,0);
	clr_bit(PORTB,4);
	clr_bit(PORTB,5);
	
	if(toggle_f == 1){
		SSD_WRITE(desired_temp);
	}
	else{
		SSD_OFF();
	}
	
	if((UP_PRESS() == PRESSED) && (desired_temp < 75)){
		desired_temp = desired_temp + 5;
		setting_counter = 0;
		SSD_WRITE(desired_temp);
	}
	else if ((DOWN_PRESS() == PRESSED) && (desired_temp > 35)){
		desired_temp = desired_temp - 5;
		setting_counter = 0;
		SSD_WRITE(desired_temp);
	}
	
	EEPROM_WRITE(0x0000,desired_temp);
	
}

void CHAGE_TEMP(void){
	if( (desired_temp < avg_temp + 5) && (desired_temp > avg_temp - 5) ){
		clr_bit(PORTB,0);
		clr_bit(PORTB,4);
		clr_bit(PORTB,5);
	}
	else if(desired_temp < avg_temp + 5){
		
		clr_bit(PORTB,4);
		set_bit(PORTB,5);
		set_bit(PORTB,0);
	}
	else if (desired_temp > avg_temp - 5){
		
		set_bit(PORTB,4);
		clr_bit(PORTB,5);
		if (toggle_f == 1)
		{
			set_bit(PORTB,0);
		}
		else {
			clr_bit(PORTB,0);
		}
	}
}

void TEMP_INITIAL(void){
	uint16_t first_temp = ADC_READ()*0.5;
	
	for (uint8_t i = 0; i<10; i++){
		temp_arr[i]= first_temp;
	}
	
	avg_temp = AVG_TEMP(temp_arr);
	arr_counter = 0;
}

void NEW_TEMP(uint16_t * arr , uint16_t new_val){
	arr[arr_counter] = new_val;
	arr_counter ++;
	
	if (arr_counter == 10){
		arr_counter = 0;
	}
}

uint16_t AVG_TEMP(uint16_t * arr){
	uint16_t sum = 0;
	uint16_t avg;
	
	for(uint8_t i=0; i<10; i++){
		sum = sum + arr[i];
	}
	avg = (uint16_t) sum / 10;
	return avg;
}


void SLEEP(void){
	
	MCUCR&=~(1<<SM0);
	MCUCR&=~(1<<SM1);
	MCUCR&=~(1<<SM2);
	
	MCUCR|=(1<<SE);

}