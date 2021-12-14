/*
 * SYS_OPER.h
 *
 * Created: 14/12/2021 1:01:43 PM
 *  Author: lana
 */ 


#ifndef SYS_OPER_H_
#define SYS_OPER_H_
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "MACROS.h"
#include "ADC.h"
#include "BUTTONS.h"
#include "SSD.h"
#include "EEPROM.h"

#define OFF 0
#define ON 1
#define SETTING 2

uint8_t Curr_state;

uint16_t temp_arr[10];
uint16_t desired_temp;
uint16_t actual_temp;
uint16_t avg_temp;

uint8_t temp_measure_f;
uint8_t temp_measure_counter;
uint8_t setting_counter;

uint16_t toggle_f;
uint8_t arr_counter;

void SYS_INITIAL(void);
void ON_STATE(void);
void OFF_STATE(void);
void SET_STATE(void);
void CHAGE_TEMP(void);
void NEW_TEMP(uint16_t * arr , uint16_t new_val);
uint16_t AVG_TEMP(uint16_t * arr);
void TEMP_INITIAL(void);
void SLEEP(void);
#endif /* SYS_OPER_H_ */