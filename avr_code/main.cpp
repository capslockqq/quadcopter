#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "operators.h"

#include "communication/transport_layer/UART.hpp"
int main(void)
{
  I_Serial_Communication<const char *> *test1 = new UART();
  const char * hej = "123";
  test1->Send_Data(hej);
  DDRB = 0xFF; //Nakes PORTC as Output
  while(1) //infinite loop
  {
    _delay_ms(100);
    PORTB = 0xFF; //Turns ON All LEDs
  }
}
