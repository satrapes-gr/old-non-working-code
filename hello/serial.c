#include <stm32f401xe.h>
#include "serial.h"

void serial_init(){
	//Enable USART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	//Set the BaudRateRegister
	//OVER8 = 0
	//42 MHz
	//BRR = 273.4375
	//Mantissa = 273 0x111
	//Fraction = 7 0x7

	//OVER8 = 0
	//84MHz
	//BRR = 546.875
	//Mantissa = 546 0x222
	//Fraction = 14 0xE

	//OVER8 = 1
	//42MHZ
	//BRR = 546.875

	//OVER8 = 1
	//84MHz
	//1093.75
	//Mantissa = 1093 0x445
	//Fraction = 12 0xC
	//Set UE bit USART Enable
	USART2->CR1 |= 1UL << 13;
	//Set M bit for length 8 or 9 in CR1 register
	USART2->CR1 |= 1UL << 12;		//Select length 8
	//Program number of stop bits
	USART2->CR2 &= ~(3UL << 12);
	//Select 1st scenario
	USART2->BRR = 0x111 << 4 | 0x7 << 0;
	//Set TE bit in CR1 to send an idle frame as first transmission
	USART2->CR1 |= 1UL << 3;
//	USART2->CR3
//	USART2->GTPR
	USART2->DR =0x55;
	while(USART2->SR & (1UL << 6) !=1);
	USART2->CR1 |= 1UL <<3;
	USART2->DR = 0xF0;
	while(USART2->SR & (1UL << 6) !=1);
	USART2->CR1 |= 1UL <<3;
	USART2->DR = 0x0F;
	while(USART2->SR & (1UL << 6) !=1);
	USART2->CR1 |= 1UL <<3;
	USART2->DR = 0x33;
	while(USART2->SR & (1UL << 6) !=1);
	USART2->CR1 |= 1UL <<3;
	USART2->DR = 0xA5;
	while(USART2->SR & (1UL << 6) !=1);



	return;
};
