/*
 * dio_cfg.h
 *
 * Created: 9/28/2019 5:12:13 AM
 *  Author: Mohamed
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_
#include "STD_Types.h"
#include "dio_types.h"
#define PINCOUNT   32
typedef struct{
	Dio_DirType pinDirection;
	STD_levelType pinState;
	}Dio_pin_configType;
extern const Dio_pin_configType Dio_pin_config [];


void Dio_init(void);

#endif /* DIO_CFG_H_ */