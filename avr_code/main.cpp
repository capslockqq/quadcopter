#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"

#include "communication/transport_layer/UART.hpp"
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void USART_init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = 1 << RXEN0 | 1 << TXEN0;
    UCSR0C = 0 << USBS0 | 3 << UCSZ00;
}

void USART_transmit( unsigned char data ) {
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void USART_transmit_string(const char *data) {
    unsigned char c;
    while(( c = *data++ )) {
        USART_transmit(c);
        _delay_ms(10);
    }
}

void blinkLED(void* parameter)
{
	DDRB |= (1 << PB5);		// PB.5 as output
	for (;;)
	{
		PORTB &= ~(1 << PB5);	// Turn LED on
		vTaskDelay(1000);	// Wait
		PORTB |= (1 << PB5);	// Turn LED off
		vTaskDelay(1000);	// Wait
		USART_transmit_string((const char *)"Hello world");
	}
}
// MAIN PROGRAM
int main(void)
{
	// CREATE BLINKER TASK
	xTaskCreate(blinkLED, "Print", configMINIMAL_STACK_SIZE, NULL, 7, NULL );

	// START SCHELUDER
	vTaskStartScheduler();
 
	return 0;
}

// IDLE TASK
void vApplicationIdleHook(void)
{
	// THIS RUNS WHILE NO OTHER TASK RUNS
}
