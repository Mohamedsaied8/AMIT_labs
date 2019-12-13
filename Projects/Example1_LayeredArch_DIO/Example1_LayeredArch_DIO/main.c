/*
 * Example1_LayeredArch_DIO.c
 *
 * Created: 9/14/2019 11:03:29 AM
 * Author : Mohamed
 */ 
#define F_CPU	16000000
#include <util/delay.h>
#include "dio.h"
#include "dio_cfg.h"
int check=0;
int main(void)	
{		uint8 value;
	Dio_init();
    while (1) 
    {
		 Dio_WriteChannel(Dio_Channel_A0,STD_high);
		//_delay_ms(100);
		DIO_Read(Dio_Channel_A0,&value);
		if(value==1){
		//_delay_ms(10);
		check=1;

		}

    }
}

