#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32f4xx.h>        
#include "gpio.h"
#include "timer.h"

void Timer2Init(void){
	/* Enable TIM2 */
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	//TIM2_CNT Counter register

	//TIM2_PSC Prescaler register
	TIM2->PSC = 999;
	//TIM2_ARR Auto reload register
	TIM2->ARR = 41983;
	//TIM2_DIER Interrupt enable register
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
	
	//Clock selection CK_INT ( Internal clock or Internal trigger inputs (ITRx) Using one timer as a prescaler for timer 2

	//TIM2_CR1
	TIM2->CR1 |= TIM_CR1_CEN;
	return;
}

void TIM2_IRQHandler(void){
	__disable_irq();
	//If interrupt is detected
	if(TIM2->SR & (TIM_SR_UIF)){
	//Clear interrupt
		TIM2->SR &= ~(TIM_SR_UIF);
		//Switch LED_STATE
		if(GPIOA->BSRR){
			LED_OFF();
		}else{
			LED_ON();
		}
		
	}
	__enable_irq();
}
