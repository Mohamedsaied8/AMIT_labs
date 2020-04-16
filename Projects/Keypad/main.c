/*
 * main.c
 *
 *  Created on: Apr 9, 2020
 *      Author: Mohamed
 */

#include "dio_cfg.h"
#include "dio.h"
#include <util/delay.h>
#include "keypad.h"
#include "dio_types.h"
#define LED0	Dio_Channel_C2
uint8 key=0;
int main(){
	Dio_init();
	//Dio_WritePort(Dio_Port_B,0xF0);
	Dio_WritePort(Dio_Port_C,0x78);

	while(1){

	key=GetKeypressed();
	_delay_ms(10);
	if(key=='0'){
		Dio_WriteChannel(LED0,STD_high);
		_delay_ms(100);
		Dio_WriteChannel(LED0,STD_low);
		_delay_ms(100);
	}//if
	else{
		Dio_WriteChannel(LED0,STD_low);
				_delay_ms(100);
		}//else
	}//while
	return 0;
}
