/*
 * keypad_config.h
 *
 * Created: 10/11/2016 11:30:24 AM
 *  Author: Master
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include <stdint.h>
 #include "MCAL_GPIO.h"

#define Col_numbers 4
#define Row_numbers 4



typedef struct
{
	GPIO_Port_Name_t PORT_Name;
	uint8_t PIN_Number;	
}Keypad_config_t;



#endif /* KEYPAD_CONFIG_H_ */