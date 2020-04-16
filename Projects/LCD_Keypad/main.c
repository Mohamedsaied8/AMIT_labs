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
#include "lcd.h"

#define LED0	Dio_Channel_C2
uint8 key=0;
uint8 address=0x80;
int main(){
	Dio_init();
	Dio_WritePort(Dio_Port_C,0x78);
	LCD_Init();
	LCD_Clear();

while(1){

	key=GetKeypressed();
	_delay_ms(10);

	if( (key!=KEY_RELEASE)){

		LCD_Char(key);
		 key=KEY_RELEASE;
		_delay_ms(100);
		 Dio_WriteChannel(LED0,STD_high);
		 _delay_ms(1000);


	}//if
	else if(address>0x8F){
		address=0x80;
		 	Dio_WriteChannel(LED0,STD_low);
			_delay_ms(100);

		}//else

	}//while
	return 0;
}
