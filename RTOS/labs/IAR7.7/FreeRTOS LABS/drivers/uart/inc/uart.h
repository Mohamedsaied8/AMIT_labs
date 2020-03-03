#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "TM4C123GH6PM.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//colors for the terminal
#define KNRM   "\x1B[0m"
#define RED    "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE   "\x1B[34m"
#define KMAG   "\x1B[35m"
#define KCYN   "\x1B[36m"
#define WHITE  "\x1B[37m"

//prototypes
void uart_init(uint32_t baudrate,uint32_t f_cpu);
void UART_Write(uint8_t ch);
void uart_write_string(char const * string);
void uart_write_int(uint32_t number);
uint8_t UART_Read(void);




#endif  //UART_H_