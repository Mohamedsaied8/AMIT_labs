/*
 * LCD_Lib.c
 *
 * Created: 9/4/2016 3:02:47 PM
 *  Author: Master
 */ 
 #include "LCD_Lib.h"

 /*********************************************************************************************************/
 void static LCD_READ()
 {
		/* LCD enable pin high */
		LCD_EN_PORT|=(1<<LCD_EN_PIN);      
		     			
		/* delay to let the LCD read the command/data */
		_delay_us(2U);
		
			/* LCD enable pin low */
		LCD_EN_PORT&=~(1<<LCD_EN_PIN);		
		
		/* delay to let the LCD execute the command or show the data */
		_delay_ms(3U);
 }

 /**********************************************/

 void static LCD_Write_4bit_mode(char value)
 {

	/* write each bit of the high nibbles to its place */
	
	if (value&(1U<<7))  {LCD_D7_PORT|=(1U<<LCD_D7_PIN);} else {LCD_D7_PORT&=~(1U<<LCD_D7_PIN);}
	if (value&(1U<<6))  {LCD_D6_PORT|=(1U<<LCD_D6_PIN);} else {LCD_D6_PORT&=~(1U<<LCD_D6_PIN);}
	if (value&(1U<<5))  {LCD_D5_PORT|=(1U<<LCD_D5_PIN);} else {LCD_D5_PORT&=~(1U<<LCD_D5_PIN);}
	if (value&(1U<<4))  {LCD_D4_PORT|=(1U<<LCD_D4_PIN);} else {LCD_D4_PORT&=~(1U<<LCD_D4_PIN);}
	/* LCD read */
	
	LCD_READ();
	/* write each bit of the low nibbles to its place */
	
	if (value&(1U<<3))  {LCD_D7_PORT|=(1U<<LCD_D7_PIN);} else {LCD_D7_PORT&=~(1U<<LCD_D7_PIN);}
	if (value&(1U<<2))  {LCD_D6_PORT|=(1U<<LCD_D6_PIN);} else {LCD_D6_PORT&=~(1U<<LCD_D6_PIN);}
	if (value&(1U<<1))  {LCD_D5_PORT|=(1U<<LCD_D5_PIN);} else {LCD_D5_PORT&=~(1U<<LCD_D5_PIN);}
	if (value&(1U<<0))  {LCD_D4_PORT|=(1U<<LCD_D4_PIN);} else {LCD_D4_PORT&=~(1U<<LCD_D4_PIN);}
	/* LCD read */
	LCD_READ();
	
 }
 
 /**********************************************/

 void LCD_Write_Command(char command)
 {

	/* RS pin high */
	LCD_RS_PORT &=~(1U<<LCD_RS_PIN);
	
	/* RW pin low */
	LCD_RW_PORT &=~(1U<<LCD_RW_PIN);

	/* write command with 4 bit mode */
	LCD_Write_4bit_mode(command);
 }
 
 /**********************************************/

 void LCD_Go_To_X_Y(unsigned char row,unsigned char position)
 {
	// send the position to the LCD 
	if (row==LCD_ROW_1)
	{
		LCD_Write_Command(127+position);
		
	}
	
	else if(row==LCD_ROW_2)
	{
		LCD_Write_Command(191+position);
		
	}

 }

 /**********************************************/

 void LCD_Write_Character(char  character)
 {
	 /* RS pin high */
	 LCD_RS_PORT |=(1U<<LCD_RS_PIN); 
	
	 /* RW pin low */
	  LCD_RW_PORT &=~(1U<<LCD_RW_PIN);

	 /* write character with 4 bit mode */
	 LCD_Write_4bit_mode(character);
 }

 /**********************************************/

 void LCD_Write_String(char  *pointer)
 {
	while(*pointer)
	{
		LCD_Write_Character(*pointer++);
	}
 }

 /**********************************************/

 void LCD_Write_float( float  float_value)
 {
	
	// How to write a float number to the LCD :D show me :D
	 
 }

 /**********************************************/

 void LCD_Initialization(void)
 {
     /* delay for 15 ms for the LCD to power up */
	 _delay_ms(15);
	 /* set the direction for the LCD pins */
	 LCD_RS_DDR |=(1U<<LCD_RS_PIN);
	 LCD_RW_DDR |=(1U<<LCD_RW_PIN);
	 LCD_EN_DDR |=(1U<<LCD_EN_PIN);
	 LCD_D7_DDR |=(1U<<LCD_D7_PIN);
	 LCD_D6_DDR |=(1U<<LCD_D6_PIN);
	 LCD_D5_DDR |=(1U<<LCD_D5_PIN);
	 LCD_D4_DDR |=(1U<<LCD_D4_PIN);
	 /* send the initialization values as in data sheet (as commands) */
	 LCD_Write_Command(0x33U);  /* Initialization */
	 LCD_Write_Command(0x32U);	/* Initialization */
	 LCD_Write_Command(0x28U);	/* Function Set: 4-bit, 2 Line, 5x7 Dots */
	 LCD_Write_Command(0x0cU);	/* Display on ,cursor off */
	 LCD_Write_Command(0x01U);  /* Clear display , Cursor home */
 }

 /*************************************************************************************************************/

