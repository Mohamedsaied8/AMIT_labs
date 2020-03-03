/*
 * keypad.h
 *
 * Created: 10/11/2016 11:42:05 AM
 *  Author: Master
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "keypad_config.h"

void Keypad_Init(void);
uint8_t Keypad_getkey(void);


#endif /* KEYPAD_H_ */