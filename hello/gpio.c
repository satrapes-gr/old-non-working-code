#include <stm32f4xx.h>
#include "gpio.h"


void GPIOAInit(){
	//Enable GPIOA clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//Configure GPIOA pin 5 as output
	GPIOA->MODER |= (1 << (LED_PIN << 1));
	//Configure GPIOA pin 5 in max speed
	GPIOA->OSPEEDR |= (2 << (LED_PIN << 1));
}
