/*
 * dio_hw.h
 *
 * Created: 9/19/2019 6:53:26 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_


#define PORTA_REG		*((volatile uint8*)0x3B)
#define PORTB_REG		*((volatile uint8*)0x38)
#define PORTC_REG		*((volatile uint8*)0x35)
#define PORTD_REG		*((volatile uint8*)0x32)

#define PINA_REG		*((const volatile uint8*)0x39 )
#define PINB_REG		*((const volatile uint8*)0x36 )
#define PINC_REG		*((const volatile uint8*)0x33 )
#define PIND_REG		*((const volatile uint8*)0x30 )


#define DDRA_REG		*((volatile uint8*)0x3A)
#define DDRB_REG		*((volatile uint8*)0x37)
#define DDRC_REG		*((volatile uint8*)0x34)
#define DDRD_REG		*((volatile uint8*)0x31)

#endif /* DIO_HW_H_ */