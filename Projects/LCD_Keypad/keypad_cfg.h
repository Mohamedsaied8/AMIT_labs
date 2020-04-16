 /*
 * keypad_cfg.h
 *
 *  Created on: Apr 9, 2020
 *      Author: Mohamed
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "dio_types.h"
//define Number of columns and rows
#define COL_NUM		4
#define ROW_NUM		4
//define pins for rows
#define ROW1_PIN	 Dio_Channel_B5
#define ROW2_PIN	 Dio_Channel_B6
#define ROW3_PIN	 Dio_Channel_B7
#define ROW4_PIN	 Dio_Channel_A0
//for columns
#define COL1_PIN	 Dio_Channel_C3
#define COL2_PIN	 Dio_Channel_C4
#define COL3_PIN	 Dio_Channel_C5
#define COL4_PIN	 Dio_Channel_C6
//port config for rows
#define ROW1_PORT	Dio_Port_B
#define ROW2_PORT	Dio_Port_B
#define ROW3_PORT	Dio_Port_B
#define ROW4_PORT	Dio_Port_A
//for columns
#define COL1_PORT	Dio_Port_C
#define COL2_PORT	Dio_Port_C
#define COL3_PORT	Dio_Port_C
#define COL4_PORT	Dio_Port_C

#define ROW1	0
#define ROW2	1
#define ROW3	2
#define ROW4	3
//cols
#define COL1	0
#define COL2	1
#define COL3	2
#define COL4	3
#define KEY_RELEASE    255
//define types
typedef struct{
	Dio_PortType portName;
	Dio_ChannelType pin;
}Keypad_Type;


#endif /* KEYPAD_CFG_H_ */
