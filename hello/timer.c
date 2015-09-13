#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32f4xx.h>        

void Timer2Init(void){
	/* Enable TIM2 */
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	return;
}
