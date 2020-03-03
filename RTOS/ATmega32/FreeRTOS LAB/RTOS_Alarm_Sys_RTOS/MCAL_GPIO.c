/*
 * MCAL_GPIO.c
 *
 * Created: 9/3/2016 8:57:08 AM
 *  Author: Master
 */ 
 #include "MCAL_GPIO.h"
 #include <avr/io.h>


 void GPIO_Init(GPIO_Init_Param_t * gpio_Param)
 {
 /*
	01001010  // direction
	00001111  // mask
	00001010

*/
	switch(gpio_Param->Port_Name)
	{
		case PT1:
			// Set the direction
			DDRA = (DDRA &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
			PORTA = (PORTA &~(gpio_Param->Mask)) | (gpio_Param->IsPulledUp&gpio_Param->Mask);
		break;	
		case PT2:
		// Set the direction
		DDRB = (DDRB &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
		PORTB = (PORTB &~(gpio_Param->Mask)) | (gpio_Param->IsPulledUp&gpio_Param->Mask);
		break;
		case PT3:
		// Set the direction
		DDRC = (DDRC &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
		PORTC = (PORTC &~(gpio_Param->Mask)) | (gpio_Param->IsPulledUp&gpio_Param->Mask);
		break;
		case PT4:
		// Set the direction
		DDRD = (DDRD &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
		PORTD = (PORTD &~(gpio_Param->Mask)) | (gpio_Param->IsPulledUp&gpio_Param->Mask);
		break;
		default:
		// nothing changed =>> MISRA rule
		break;
		
	}
 }

 void GPIO_Write(GPIO_Write_Param_t * gpio_Param)
 {
 switch(gpio_Param->Port_Name)
 {
	 case PT1:
	 // Set the direction
	 PORTA = (PORTA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
	 break;
	 case PT2:
	 // Set the direction
	 PORTB = (PORTB &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
	 break;
	 case PT3:
	 // Set the direction
	 PORTC = (PORTC &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
	 break;
	 case PT4:
	 // Set the direction
	 PORTD = (PORTD &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
	 break;
	 default:
	 // nothing changed =>> MISRA rule
	 break;
	 
 }
 }
 uint8_t GPIO_Read(GPIO_Read_Param_t * gpio_Param)
 {
	uint8_t value = 0;
	switch(gpio_Param->Port_Name)
	{
		case PT1:
		value = (uint8_t)((PINA & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		case PT2:
		value = (uint8_t)((PINB & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		case PT3:
		value = (uint8_t)((PINC & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		case PT4:
		value = (uint8_t)((PIND & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		default:
		/* nothing changed =>> MISRA rule */
		break;
		
	}
	return value;
 }