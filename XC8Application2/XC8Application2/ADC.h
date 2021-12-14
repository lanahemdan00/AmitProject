/*
 * ADC.h
 *
 * Created: 14/12/2021 6:13:03 PM
 *  Author: lana
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include "MACROS.h"


void ADC_INITIAL(void);
uint16_t ADC_READ(void);
#endif /* ADC_H_ */