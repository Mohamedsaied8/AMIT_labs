/*
 * dio_cfg.c
 *
 * Created: 9/28/2019 5:18:46 AM
 *  Author: Mohamed
 */ 
#include "dio_cfg.h"
#include "dio_hw.h"
#include "bit_math.h"

const Dio_pin_configType Dio_pin_config[]={
/*PA0*/		{Output,STD_low},
/*PA1*/		{Output,STD_low},
/*PA2*/		{Output,STD_low},
/*PA3*/		{Output,STD_low},
/*PA4*/		{Output,STD_low},
/*PA5*/		{Output,STD_low},
/*PA6*/	   	{Output,STD_low},
/*PA7*/		{Output,STD_low},
/*PB0*/		{Output,STD_low},	
/*PB1*/		{Output,STD_low},//LCD_RS
/*PB2*/		{Output,STD_low},//LCD_RW
/*PB3*/		{Output,STD_low},//LCD_EN
/*PB4*/		{Output,STD_low},
/*PB5*/		{Output,STD_low},
/*PB6*/		{Output,STD_low},
/*PB7*/		{Output,STD_low},
/*PC0*/		{Output,STD_low},	
/*PC1*/		{Output,STD_low},	
/*PC2*/		{Output,STD_low},	
/*PC3*/		{Input,STD_low},
/*PC4*/		{Input,STD_low},
/*PC5*/		{Input,STD_low},
/*PC6*/		{Input,STD_low},
/*PC7*/		{Output,STD_low},
/*PD0*/		{Output,STD_low},
/*PD1*/		{Output,STD_low},
/*PD2*/		{Output,STD_low},
/*PD3*/		{Output,STD_low},
/*PD4*/		{Output,STD_low},
/*PD5*/		{Output,STD_low},
/*PD6*/		{Output,STD_low},
/*PD7*/		{Output,STD_low},
};

void Dio_init(void)
{
	uint8 counter;
	uint8 currentPin ;
	uint8 currentPort;
	for(counter =Dio_Channel_A0; counter <PINCOUNT ; counter++)
	{
		currentPin = counter % 8;
		currentPort = counter /8;
		if(Dio_pin_config[counter].pinDirection ==Output)
		{
			switch (currentPort)
			{
				case Dio_Port_A:
				SET_BIT(DDRA_REG,currentPin);
				break;
				case Dio_Port_B:
				SET_BIT(DDRB_REG,currentPin);
				break;
				case Dio_Port_C:
				SET_BIT(DDRC_REG,currentPin);
				break;
				case Dio_Port_D:
				SET_BIT(DDRD_REG,currentPin);
				break;
			}//switch
		}//if
		else
		{
			switch (currentPort)
			{
				case Dio_Port_A:
				CLR_BIT(DDRA_REG,currentPin);
				break;
				case Dio_Port_B:
				CLR_BIT(DDRB_REG,currentPin);
				break;
				case Dio_Port_C:
				CLR_BIT(DDRC_REG,currentPin);
				break;
				case Dio_Port_D:
				CLR_BIT(DDRD_REG,currentPin);
				break;
			}//switch
			
		}//else
	}//for
}//func
