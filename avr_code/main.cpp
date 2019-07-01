#ifndef F_CPU
#define F_CPU 16000000 // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <stdio.h>
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"

#include "communication/transport_layer/UART.hpp"


#include <avr/io.h> 
#include <util/delay.h>

void blinkLED(void* parameter)
{
	DDRB |= (1 << PB5);		// PB.5 as output
	for (;;)
	{
		PORTB &= ~(1 << PB5);	// Turn LED on
		vTaskDelay(1000);	// Wait
		PORTB |= (1 << PB5);	// Turn LED off
		vTaskDelay(1000);	// Wait

	}
}
// MAIN PROGRAM
/*int main(void)
{
	// CREATE BLINKER TASK
	xTaskCreate(blinkLED, "Print", configMINIMAL_STACK_SIZE, NULL, 7, NULL );

	// START SCHELUDER
	vTaskStartScheduler();
 
	return 0;
}*/

// IDLE TASK
void vApplicationIdleHook(void)
{
	// THIS RUNS WHILE NO OTHER TASK RUNS
}


#define BUAD    9600
#define BRC     ((F_CPU/8/BUAD) - 1)
#define TX_BUFFER_SIZE  128
 
#include <util/delay.h>
#include <avr/interrupt.h>
char serialBuffer[TX_BUFFER_SIZE];
uint8_t serialReadPos = 0;
uint8_t serialWritePos = 0;
 
void appendSerial(char c);
void serialWrite(const char *c);
 
int main(void)
{   
    UBRR0H = (BRC >> 8);
    UBRR0L =  BRC;
    UCSR0B = (1 << TXEN0)  | (1 << TXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
     
    sei();
         
    while(1)
    {
		appendSerial('1');
		_delay_ms(1000);
    }
}
 
void appendSerial(char c)
{
    while ( !( UCSR0A & (1<<UDRE0)));
    /* Put data into buffer, sends the data */
    UDR0 = c;
}
 
void serialWrite(const char *c)
{
	int i = 0;
	while(c[i] != '\0') {
		appendSerial(c[i]);
		i++;
	}
}
