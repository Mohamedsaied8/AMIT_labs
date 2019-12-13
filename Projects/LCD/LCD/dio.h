/*
 * dio.h
 *
 * Created: 9/14/2019 12:53:24 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "dio_types.h"
#include "STD_Types.h"

void Dio_WriteChannel(Dio_ChannelType Channel, STD_levelType level);
void Dio_WritePort(Dio_PortType portx,uint8 uxvalue);
void DIO_Read(Dio_ChannelType channel,uint8 *data);
void Dio_FlipChannel( Dio_ChannelType ChannelId);
STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId); //TODO
/*=========================================
 * FUNCTIONS PROTOTYPES
 =========================================*/
//STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId);
//uint8 Dio_ReadPort(Dio_PortType PortId );

/*void Dio_WritePort( Dio_PortType PortId, uint8 Level);
void Dio_FlipPort(Dio_PortType PortId);*/
#endif /* DIO_H_ */