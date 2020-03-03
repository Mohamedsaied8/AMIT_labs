#include "uart.h"




void uart_init(uint32_t baudrate,uint32_t f_cpu)
{
float brd,temp;  
  
//  1. Enable the UART module using the RCGCUART register (see page 337).
  SYSCTL->RCGCUART |=(1U<<0);
//2. Enable the clock to the appropriate GPIO module via the RCGCGPIO register (see page 334).
//To find out which GPIO port to enable, refer to Table 22-5 on page 1315.
  SYSCTL->RCGCGPIO |=(1U<<0);
  //SYSCTL->GPIOHBCTL|=(1U<<0);
//3. Set the GPIO AFSEL bits for the appropriate pins (see page 631). To determine which GPIOs to
//configure, see Table 22-4 on page 1308.
  GPIOA->AFSEL |=(1U<<0)|(1U<<1);
  GPIOA->DEN   |=(1U<<0)|(1U<<1); 
//4. Configure the GPIO current level and/or slew rate as specified for the mode selected (see
//page 633 and page 641).
//5. Configure the PMCn fields in the GPIOPCTL register to assign the UART signals to the appropriate
//pins (see page 648 and Table 22-5 on page 1315).
  GPIOA->PCTL |=(1U<<0)|(1U<<4);

//UART clock is assumed to be 16 MHz, and the desired UART configuration is:
//¦ 115200 baud rate
//¦ Data length of 8 bits
//¦ One stop bit
//¦ No parity
//¦ FIFOs disabled
//¦ No interrupts
//The first thing to consider when programming the UART is the baud-rate divisor (BRD), because
//the UARTIBRD and UARTFBRD registers must be written before the UARTLCRH register. Using
//the equation described in “Baud-Rate Generation” on page 856, the BRD can be calculated:
brd = (float)f_cpu / (16 * baudrate);
temp = (float)brd - (uint32_t)brd;
//which means that the DIVINT field of the UARTIBRD register (see page 874) should be set to 10
//decimal or 0xA. The value to be loaded into the UARTFBRD register (see page 875) is calculated
//by the equation:
//UARTFBRD[DIVFRAC] = integer(0.16667 * 64 + 0.5) = 11
//With the BRD values in hand, the UART configuration is written to the module in the following order:
//1. Disable the UART by clearing the UARTEN bit in the UARTCTL register.
  UART0->CTL &=~(1U<<0);
//2. Write the integer portion of the BRD to the UARTIBRD register.
  UART0->IBRD = (uint32_t)brd;
//3. Write the fractional portion of the BRD to the UARTFBRD register.
  UART0->FBRD = (uint32_t)(((float)temp * 64 )+ 0.5);
//4. Write the desired serial parameters to the UARTLCRH register (in this case, a value of
//0x0000.0060).
  UART0->LCRH |=(0x3<<5);
//5. Configure the UART clock source by writing to the UARTCC register.
  UART0->CC = 0x00;
//6. Optionally, configure the µDMA channel (see “Micro Direct Memory Access (µDMA)” on page 545)
//and enable the DMA option(s) in the UARTDMACTL register.
//7. Enable the UART by setting the UARTEN bit in the UARTCTL register.
UART0->CTL |=(1U<<0)|(1U<<8)|(1U<<9);
  
}

   
 void UART_Write(uint8_t ch)
{
  while((UART0->FR & (1U<<7))==0);  /* wait for transmitter buffer to be free*/
  UART0->DR = ch;
}
uint8_t UART_Read(void)
{
  char data;
  while((UART0->FR & (1U<<6))==0);  /* wait for reciever buffer to have data*/
  data = UART0->DR;
  return data;
}

void uart_write_string(char const * string)
{
  while(*string != '\0')
  {
    UART_Write(*string);
    string++;
  }
}

void uart_write_int(uint32_t number)
{
  uint16_t length = snprintf( NULL, 0, "%d", number );
  char* str = malloc( length + 1 );
  snprintf( str, length + 1, "%d", number );
  free(str);
  uart_write_string(str);
}