/*
 * LCD.c
 *
 * Created: 12/10/2019 3:25:34 PM
 * Author : Mohamed
 */ 

#include "lcd.h"
#include "dio_cfg.h"
char heart[8] = {
	0b00000,
	0b01010,
	0b11111,
	0b11111,
	0b11111,
	0b01110,
	0b00100,
	0b00000
};
char smileyFace[8] = {
	0x00,//0B00000
	0x00,
	0x0A,
	0x00,
	0x11,
	0x0E,
	0x00,
	0x00
};

	
int main(void)
{
	int i=0;
	Dio_init();
	LCD_Init();
	LCD_Command(0x80);
	LCD_String("Welcome to AMIT");
	LCD_Char(' ');		/* space between each custom char. */
	
	LCD_Custom_Char(0,smileyFace); //
	LCD_Command(0x8F);
	LCD_Char(0);	/* char at '0'th position will display on lcd */
	
	Dio_WriteChannel(Dio_Channel_C2,STD_high);
	_delay_ms(1000);

   while (1) 
    {
		

    }
}

