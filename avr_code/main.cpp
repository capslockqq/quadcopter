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
		vTaskDelay(250);	// Wait
	}
}
int main(void)
{
  xTaskCreate(blinkLED, "blink", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
  while(1) //infinite loop
  {
    _delay_ms(100);
    PORTB = 0xFF; //Turns ON All LEDs
  }
}
