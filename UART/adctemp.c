#include "adctemp.h"

void ADCTempInit(void){
	//Temperature sensor and Vrefint enable
	ADC->CCR |= (1<<23);
}
