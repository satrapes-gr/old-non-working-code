#include "serial.h"

void serialInit(){
	//Enable clock for USART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN; //check

	//Configure PA2 GPIO pin USART2_TX (output) alternate function
	//Select alternate function for PA2
	GPIOA->MODER &= ~(3UL << (2 << 1));	//check
	GPIOA->MODER |= (2UL << (2 << 1));	//check

	//Select push/pull
	GPIOA->OTYPER &= ~(1 << 2);	//check (can be omitted)

	//Select low speed for PA2
	GPIOA->OSPEEDR &= ~(3UL << (2 << 1));	//check
	GPIOA->OSPEEDR |= (3 << (2 << 1));		//check

	//no pull-up pulldown
	GPIOA->PUPDR &= ~(3 << (2 << 1));	//check (can be omitted)

	//Select USART2 alternate function for PA2
	GPIOA->AFR[0] &= ~(15UL << (4 * 2));	//check
	GPIOA->AFR[0] |= (7UL << (4 * 2));	//check


	//Configure PA3 GPIO pin USART2_RX (input) alternate function
	//Select alternate functioin for PA3
	GPIOA->MODER &= ~(3UL << (3 << 1));	//check
	GPIOA->MODER |= (2UL << (3 << 1));	//check

	//push pull
	GPIOA->OTYPER &= ~(1 << 2);	//check (can be omitted)

	//select high speed for PA3
	GPIOA->OSPEEDR &= ~(3UL << (3 << 1));	//check
	GPIOA->OSPEEDR |= (3 << (3 << 1));		//check

	//no pull-up pulldown
	GPIOA->PUPDR &= ~(3 << (3 << 1));	//check (can be omitted)

	//Select USART2 alternate function for PA3
	GPIOA->AFR[0] &= ~(15UL << (4*3));	//check
	GPIOA->AFR[0] |= (7UL << (4*3));	//check

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

int sendChar(int ch){
	USART2->DR = (ch & 0xFF);
	while (!(USART2->SR & (1UL << 6)));
	return ch;
}
