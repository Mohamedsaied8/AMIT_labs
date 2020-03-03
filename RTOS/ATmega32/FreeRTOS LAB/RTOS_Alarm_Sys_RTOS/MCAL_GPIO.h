/*
 * MCAL_GPIO.h
 *
 * Created: 9/3/2016 8:56:46 AM
 *  Author: Master
 */ 


#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_
#include <stdint.h>

typedef enum
{
	PT1,
	PT2,
	PT3,
	PT4
}GPIO_Port_Name_t;

typedef struct
{
	GPIO_Port_Name_t Port_Name;
	uint8_t Mask;
	uint8_t Direction;
	uint8_t IsPulledUp;
}GPIO_Init_Param_t;

typedef struct
{
	GPIO_Port_Name_t Port_Name;
	uint8_t Mask;
	uint8_t Data;
}GPIO_Write_Param_t;

typedef struct
{
	GPIO_Port_Name_t Port_Name;
	uint8_t PIN_Number;
}GPIO_Read_Param_t;

void GPIO_Init(GPIO_Init_Param_t * gpio_Param);
void GPIO_Write(GPIO_Write_Param_t * gpio_Param);
uint8_t GPIO_Read(GPIO_Read_Param_t * gpio_Param);

#endif /* MCAL_GPIO_H_ */