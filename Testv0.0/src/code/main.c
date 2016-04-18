#include <stm32f4xx.h>		//CMSIS-Core file
							//Includes system_stm32f4xx.h and
							//core_cm4.h
#include "gpio.h"
#include "UARTDriver.h"

int main(){
	uint8_t i;
	uint8_t result;
	uint8_t *string = "O Satrapis einai 8eos\r\n";
	GPIOAInit();
	serialInit();
	while(1){
		i = sendString(string);
		if(i != 23){
			sendChar(1);
		}else{
			sendChar(0);
		}
	}
	return 0;
}
