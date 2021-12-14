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


int main(void)
{
	SYS_INITIAL();
    while(1)
    {
		switch(Curr_state)
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
			default:
			{
				break;

			}
		}
		return(0);
	}
}

	