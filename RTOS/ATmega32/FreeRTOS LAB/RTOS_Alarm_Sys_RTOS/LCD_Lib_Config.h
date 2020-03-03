/*
 * LCD_Lib_Config.h
 *
 * Created: 9/4/2016 3:13:34 PM
 *  Author: Master
 */ 


#ifndef LCD_LIB_CONFIG_H_
#define LCD_LIB_CONFIG_H_

/*************** MCU Clock definition for LCD delay function ***********/

//#define  F_CPU			(16000000UL)
#include <avr/io.h>

/**************** LCD Control pins **************************/
#define LCD_RS_DDR		(DDRB)									 	
#define LCD_RS_PORT		(PORTB)
#define LCD_RS_PIN		(PB1)


#define LCD_RW_DDR		(DDRB)
#define LCD_RW_PORT		(PORTB)
#define LCD_RW_PIN		(PB2)

#define LCD_EN_DDR		(DDRB)
#define LCD_EN_PORT		(PORTB)
#define LCD_EN_PIN		(PB3)

/**************** LCD DATA pins ********************/
#define LCD_D4_DDR		(DDRA)
#define LCD_D4_PORT		(PORTA)
#define LCD_D4_PIN		(PA4)

#define LCD_D5_DDR		(DDRA)
#define LCD_D5_PORT		(PORTA)
#define LCD_D5_PIN		(PA5)

#define LCD_D6_DDR		(DDRA)
#define LCD_D6_PORT		(PORTA)
#define LCD_D6_PIN		(PA6)

#define LCD_D7_DDR		(DDRA)
#define LCD_D7_PORT		(PORTA)
#define LCD_D7_PIN		(PA7)

/**********************************************************************/



#endif /* LCD_LIB_CONFIG_H_ */