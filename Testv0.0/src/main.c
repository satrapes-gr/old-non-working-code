#include <stm32f4xx.h>		//CMSIS-Core file
							//Includes system_stm32f4xx.h and
							//core_cm4.h
#include "gpio.h"
#include "serial.h"

int main(){
	uint8_t i;
	uint8_t result;
	GPIOAInit();
	serialInit();
	while(1){
		for(i=0; i<256; i++){
			result = sendChar(i);
			result += 1;
		}
	}
	return 0;
}
