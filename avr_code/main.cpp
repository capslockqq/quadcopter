#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <avr/delay.h>
#include <stdio.h>
#include <util/delay.h>
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

#define BAUD 9600 
#define MYUBRR    F_CPU/16/BAUD-1

void init_uart(unsigned short uValue  ){
    // setting the baud rate  based on the datasheet 
    UBRR0H =0x00;//(unsigned char)  ( uValue>> 8);  // 0x00 
    UBRR0L =0x0C;//(unsigned char) uValue;  // 0x0C  
    // enabling TX & RX 
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0A = (1<<UDRE0)|(1<<U2X0);
    UCSR0C =  (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stop

}

unsigned char USART_Receive( void )
{
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) )
    ;
    /* Get and return received data from buffer */
    return UDR0;
}
void USART_Transmit( unsigned char data )
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) )
    ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

int main (){
    init_uart(MYUBRR);
    DDRD |= (1<< PD7);
    for(;;){
        PORTD ^= (1<< PD7);
        USART_Transmit('x');
        USART_Transmit('l');
        _delay_ms(1000);
    }
    return 0;
}