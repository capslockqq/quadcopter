#define F_CPU 16000000UL // 16 MHz clock speed

#include <avr/io.h>
#include <stdio.h>
#include "../FreeRTOS_avr/include/FreeRTOS.h"
#include "../FreeRTOS_avr/include/task.h"
#include "communication/transport_layer/UART.hpp"
#include "operators.h"

#include "../FreeRTOS_tasks/tasks.hpp"
#include "../application_code/components/Binds.hpp"
#define BUAD    9600
#define BRC     ((F_CPU/8/BUAD) - 1)
 
 
void appendSerial(char c);
void serialWrite(const char *c);
void InitUART() {
	UBRR0H = (BRC >> 8);
    UBRR0L =  BRC;
    UCSR0B = (1 << TXEN0)  | (1 << TXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

// MAIN PROGRAM
int main(void)
{
	InitUART();
	SetUp_Tasks();
	return 0;
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
