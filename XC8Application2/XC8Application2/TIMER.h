/*
 * TIMER.h
 *
 * Created: 15/12/2021 10:49:44 PM
 *  Author: lana
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include "MACROS.h"

void timer1_init(void);

void timer0_init(void);

void timer1_INT_disable(void);

void timer1_INT_enable(void);
#endif /* TIMER_H_ */