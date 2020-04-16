/*
 * STD_Types.h
 *
 * Created: 9/16/2019 10:57:24 PM
 *  Author: Mohamed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

//unsigned
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long long uint32;
//signed
typedef  char int8;
typedef  int int16;
typedef  long long int32;


typedef enum
{
	STD_low=0,
	STD_high=!STD_low
}STD_levelType;

	

#endif /* STD_TYPES_H_ */