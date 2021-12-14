/*
 * BUTTONS.h
 *
 * Created: 14/12/2021 6:27:49 PM
 *  Author: lana
 */ 



#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MACROS.h"

#define PRESSED 1
#define NOT_PRESSED 0
#define ON_OFF_PIN 2
#define UP_PIN 1
#define DOWN_PIN 3

void BUTTONS_INIT(void);
void ON_OFF_EXTI(void);

unsigned char UP_PRESS(void);
unsigned char DOWN_PRESS(void);
#endif /* BUTTONS_H_ */