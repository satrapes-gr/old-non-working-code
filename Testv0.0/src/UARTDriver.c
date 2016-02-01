#include "UARTDriver.h"

void serialInit(){
	//Enable clock for USART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN; //check

	//Set TE bit to send an idle frame as first transmission
	USART2->CR1 |= 1UL <<3;	//check

	//Set Mbit for length 8
	USART2->CR1 |= 1UL << 12;	//check (can be omitted)

	//Program number of stop bits
	USART2->CR2 &= ~(3UL << 12);	//check

	//Select baud rate 9600
	//USART peripherals operate at the internal 16 MHz oscillator (HSI)
	//frequency
	//OVER8 = 0
	//fpclk = 42MHz
	//BRR = 273.4375
	//Mantissa = 273 0x111
	//Fraction = 7 0x7
	USART2->BRR &= ~(0xFFFF);	//check
	USART2->BRR = 0x111 << 4 | 0x7 << 0;	//check

	//USART2->BRR = SystemCoreClock/115200L;	//Second way to set baudrate


	//Set UE bit USART Enable
	USART2->CR1 |= 1UL << 13;
}

uint8_t sendChar(uint8_t ch){
	USART2->DR = (ch & 0xFF);
	while (!(USART2->SR & (1UL << 6)));
	return ch;
}
