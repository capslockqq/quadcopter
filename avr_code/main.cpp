#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "operators.h"
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"

#include "communication/transport_layer/UART.hpp"

void blinkLED(void* parameter)
{
	DDRB |= (1 << PB5);		// PB.5 as output
	for (;;)
	{
		PORTB &= ~(1 << PB5);	// Turn LED on
		vTaskDelay(250);	// Wait
		PORTB |= (1 << PB5);	// Turn LED off
		vTaskDelay(1000);	// Wait
	}
}
// MAIN PROGRAM
int main(void)
{
	// CREATE BLINKER TASK
	xTaskCreate(blinkLED, "blink", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);

	// START SCHELUDER
	vTaskStartScheduler();
 
	return 0;
}

// IDLE TASK
void vApplicationIdleHook(void)
{
	// THIS RUNS WHILE NO OTHER TASK RUNS
}
