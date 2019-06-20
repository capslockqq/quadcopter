#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "operators.h"

#include "../application_code/communication/transportation/UART.hpp"
int main(void)
{

  UART *lol = new UART();
  DDRB = 0xFF; //Nakes PORTC as Output
  while(1) //infinite loop
  {
    _delay_ms(100);
    if (lol->dummy()) {
      PORTB = 0xFF; //Turns ON All LEDs
    } 

    
  }
}
