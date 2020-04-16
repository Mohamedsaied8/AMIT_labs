/*
 * lcd.c
 *
 * Created: 5/19/2019 11:13:19 AM
 *  Author: Mohamed
 */ 
#include "lcd.h"
#include "dio.h"

/*

Initialization

Wait for 15ms, Power on initialization time for LCD16x2.
Send 0x02 command which initializes LCD 16x2 in 4-bit mode.
Send 0x28 command which configures LCD in 2-line, 4-bit mode and 5x8 dots.
Send any Display ON command (0x0E, 0x0C)
Send 0x06 command (increment cursor)
*/
void LCD_Init (void)  /* LCD Initialize function */
{
	Dio_WriteChannel(RW,STD_low);
	_delay_ms(20);		/* LCD Power ON delay always >15ms */
	
	LCD_Command(0x33); //3 3 3 2
	LCD_Command(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_Command(0x28);	/* 2 line, 5*8 matrix in 4-bit mode */
	LCD_Command(0x0c);	/* Display on cursor off */
	LCD_Command(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_Command(0x01);	/* Clear display screen */
}
/*Command write function

First, send Higher nibble of command.
Make RS pin low, RS=0 (command reg.)
Make RW pin low, RW=0 (write operation) or connect it to ground.
Give High to Low pulse at Enable (E).
Send lower nibble of command.
Give High to Low pulse at Enable (E).
*/
void LCD_Command( unsigned char cmnd )
{
	//LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);/* Sending upper nibble */
	Dio_WritePort(Dio_Port_A,((LCD_Port & 0x0F) | (cmnd & 0xF0)));
	Dio_WriteChannel(RS,STD_low);/* RS=0, command reg. */
	 Dio_WriteChannel(EN,STD_high);		/* Enable pulse */
	_delay_us(10);
	 Dio_WriteChannel(EN,STD_low);
	_delay_us(2000);
	//LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);/* Sending lower nibble */
	Dio_WritePort(Dio_Port_A,((LCD_Port & 0x0F) | (cmnd << 4)));
	Dio_WriteChannel(EN,STD_high);	
	_delay_us(1);
	Dio_WriteChannel(EN,STD_low);
	_delay_ms(2);
}

/*Data write function

First send Higher nibble of data.
Make RS pin high, RS=1 (data reg.)
Make RW pin low, RW=0 (write operation) or connect it to ground.
Give High to Low pulse at Enable (E).
Send lower nibble of data.
Give High to Low pulse at Enable (E).
*/
void LCD_Char( unsigned char data )
{
	//LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);/* Sending upper nibble */
	Dio_WritePort(Dio_Port_A,((LCD_Port & 0x0F) | (data & 0xF0)));
	Dio_WriteChannel(RS,STD_high);
	Dio_WriteChannel(EN,STD_high);
	_delay_us(1);
	Dio_WriteChannel(EN,STD_low);
	_delay_us(2000);
	Dio_WritePort(Dio_Port_A,((LCD_Port & 0x0F) | (data << 4)));  /* Sending lower nibble */
	Dio_WriteChannel(EN,STD_high);
	_delay_us(1);
	Dio_WriteChannel(EN,STD_low);
	_delay_ms(20);
}

/*

*/
void LCD_String(char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}
/*

*/
void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}
/*

*/
void LCD_Clear()
{
	LCD_Command (0x01);		/* Clear display */
	_delay_ms(2);
	LCD_Command (0x80);		/* Cursor at home position */
}


void LCD_Custom_Char(unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc<8)
	{
		LCD_Command (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_Char(msg[i]);
	}
}
