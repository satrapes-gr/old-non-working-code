#include "gpio.h"

void GPIOAInit(){
	//Enable GPIOA clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	//check

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
	
	//Configure GPIOA pin 5 as output
	GPIOA->MODER |= (1 << (LED_PIN << 1));

	//Configure GPIOA pin 5 in max speed
	GPIOA->OSPEEDR |= (2 << (LED_PIN << 1));
	LED_ON();

}


