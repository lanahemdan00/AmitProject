/*
 * MACROS.h
 *
 * Created: 14/12/2021 12:43:18 PM
 *  Author: lana
 */ 

//MACROS FOR BITS OF THE REGISTER
#ifndef MACROS_H_
#define MACROS_H_

#define set_bit(reg,bit) reg=reg|(1<<bit)
#define clr_bit(reg,bit) reg=reg&(~(1<<bit))
#define tog_bit(reg,bit) reg=reg^(1<<bit)
#define read_bit(reg,bit) reg&(1<<bit)
#define is_bit_set(reg,bit) reg&(1<<bit)>>bit
#define is_bit_clr(reg,bit) !(reg&(1<<bit)>>bit)






#endif /* MACROS_H_ */