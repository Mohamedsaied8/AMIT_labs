/*
 * lcd_cfg.h
 *
 * Created: 12/10/2019 6:13:34 PM
 *  Author: Mohamed
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_


#include "dio_hw.h"
#include "dio_types.h"

//#define LCD_Dir				  DDRA_REG			/* Define LCD data port direction */
#define LCD_Port			  PORTA_REG			/* Define LCD data port */
//#define LCD_Dir_Control		  DDRB_REG			/* Define LCD Control port direction */
#define LCD_Port_Control	  PORTB_REG			/* Define LCD Control port direction */

#define RS					  Dio_Channel_B1	/* Define Register Select pin */
#define EN					  Dio_Channel_B3
#define RW					  Dio_Channel_B2			/* Define Register Select pin */



#endif /* LCD_CFG_H_ */