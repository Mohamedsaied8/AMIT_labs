/*
 * lcd.h
 *
 * Created: 5/19/2019 11:36:55 AM
 *  Author: Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL			/* Define CPU Frequency e.g. here 8MHz */
#include <util/delay.h>			/* Include Delay header file */
#include "lcd_cfg.h"


void LCD_Init (void) ;
void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_String (char *str);
void LCD_Clear();

void LCD_String_xy (char row, char pos, char *str);
void LCD_Custom_Char(unsigned char loc, unsigned char *msg);


#endif /* LCD_H_ */