/*
 * SSD.h
 *
 * Created: 14/12/2021 7:54:01 PM
 *  Author: lana
 */ 


#ifndef SSD_H_
#define SSD_H_


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "MACROS.h"
	

#define DISP1 1
#define DISP2 2


	
void SSD_INITIAL(void);
void SSD_NUM(uint16_t);
void SSD_ENAB(uint8_t);
void SSD_DISAB(void);
void SSD_OFF(void);
void SSD_WRITE(uint16_t);

#endif /* SSD_H_ */