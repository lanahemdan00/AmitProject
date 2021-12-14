/*
 * EEPROM.h
 *
 * Created: 14/12/2021 7:50:44 PM
 *  Author: lana
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include <avr/io.h>
#include "MACROS.h"
void EEPROM_WRITE(const unsigned short addr, unsigned char data);
unsigned char EEPROM_READ(const unsigned short addr);
#endif /* EEPROM_H_ */