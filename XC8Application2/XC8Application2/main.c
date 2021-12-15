/*
 * main.c
 *
 * Created: 12/14/2021 12:40:17 PM
 *  Author: lana
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "SYS_OPER.h"
#include "MACROS.h"
#define F_CPU 100000UL


int main(void){
	
	SYS_INITIAL();
	
	while(1){
		switch (Curr_state)
		{
			case ON:
			{
				ON_STATE();
				break;
			}
			case OFF:
			{
				OFF_STATE();
				break;
			}
			case SETTING:
			{
				SET_STATE();
				break;
			}
			default :
			{
				//Nothing
				break;
			}
		}
	}
	
	return (0);
}



ISR(INT2_vect){
	if(Curr_state==OFF){
		Curr_state = ON;
		desired_temp = EEPROM_READ(0x0000);
	}
	else if (Curr_state==ON || Curr_state==SETTING){
		Curr_state = OFF;
	}
}


ISR(TIMER1_COMPA_vect){
	temp_measure_f = 1;
}

ISR(TIMER0_COMP_vect){
	if ((Curr_state==SETTING) || (Curr_state==ON)){
		setting_counter++;
		if(setting_counter % 4 == 0){
			toggle_f ^= 1;
		}
		if (setting_counter > 20){
		
			Curr_state = ON;
		}
	}
}


	