#include "serial.h"

void serialInit(){
	//Enable clock for USART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	//Configure PA2 GPIO pin USART2_TX (output) alternate function
	//Select alternate function for PA2
	GPIOA->MODER &= ~(3UL << (2 << 1));		
	GPIOA->MODER |= (2UL << (2 << 1));

	//Select low speed for PA2
	GPIOA->OSPEEDR &= ~(3UL << (2 << 1));

	//Select USART2 alternate function for PA2
	GPIOA->AFR[0] &= ~(15UL << (4*2));
	GPIOA->AFR[0] |= (7UL << (4*2));


	//Configure PA3 GPIO pin USART2_RX (input) alternate function
	//Select alternate functioin for PA3
	GPIOA->MODER &= ~(3UL << (3 << 1));
	GPIOA->MODER |= (2UL << (3 << 1));

	//select low speed for PA3
	GPIOA->OSPEEDR &= ~(3UL << (3 << 1));

	//Select USART2 alternate function for PA3
	GPIOA->AFR[0] &= ~(15UL << (4*3));
	GPIOA->AFR[0] |= (7UL << (4*3));

	//Set Mbit for length 8
	USART2->CR1 |= 1UL << 12;

	//Program number of stop bits
	USART2->CR2 &= ~(3UL << 12);

	//Select baud rate 9600
	//USART peripherals operate at the internal 16 MHz oscillator (HSI)
	//frequency
	//OVER8 = 0
	//fpclk = 42MHz
	//BRR = 273.4375
	//Mantissa = 273 0x111
	//Fraction = 7 0x7
	USART2->BRR &= ~(0xFFFF);
	USART2->BRR = 0x111 << 4 | 0x7 << 0;

	//USART2->BRR = SystemCoreClock/115200L;	//Second way to set baudrate

	//Set TE bit to send an idle frame as first transmission
	USART2->CR1 |= 1UL <<3;
	//Set UE bit USART Enable
	USART2->CR1 |= 1UL << 13;
}

int sendChar(int ch){
	USART2->DR = (ch & 0xFF);
	while (!(USART2->CR1 & (1UL << 6)));
	return ch;
}
