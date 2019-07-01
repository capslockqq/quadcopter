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

#include <avr/io.h> 
#include <util/delay.h>

void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );


void USART_Init( unsigned int ubrr)
{
	/*Set baud rate */
	/* UBRR0H contains the 4 most significant bits of the
	baud rate. UBRR0L contains the 8 least significant
	bits.*/  
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	

	/*Enable transmitter */
	UCSR0B = (1<<TXEN0);
	
	/* Set frame format: 8data */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	
	/* Put data into buffer, sends the data */
	UDR0 = data;
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
		USART_Transmit('H');
		USART_Transmit('E');
		USART_Transmit('L');
		USART_Transmit('L');
		USART_Transmit(' ');
		USART_Transmit('W');
		USART_Transmit('O');
		USART_Transmit('R');
		USART_Transmit('L');
		USART_Transmit('D');
		USART_Transmit('\n');
	}
}
// MAIN PROGRAM
int main(void)
{
	USART_Init(MYUBRR);
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
