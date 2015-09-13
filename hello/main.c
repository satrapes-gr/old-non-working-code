/*Copyright (C) Patryk Jaworski <regalis@regalis.com.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
*/
#include <stm32f4xx.h>

#include <stdio.h>
#include "serial.h"
#include "timer.h"
#include "gpio.h"
 
int main() {
	GPIOAInit();
	Timer2Init();
//    volatile int i = 0;
	/* Turn on the LED */
	while(1){
/*		//printf("Turning LD2 off\n");
		LED_OFF();
		//printf("Waiting...\n");
		for (i=0;i<3000000;i++){
			i++;
		}
		//printf("Turning LD2 on\n");
		LED_ON();
		//printf("Waiting...\n");
		for (i=0;i<3000000;i++){
			i++;
		}*/
		;
	}
	return 0;
}
