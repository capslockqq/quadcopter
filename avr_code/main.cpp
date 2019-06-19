#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <CLed.hpp>
int main(void)
{

  DDRB = 0xFF; //Nakes PORTC as Output
  while(1) //infinite loop
  {
    PORTB = 0xFF; //Turns ON All LEDs

    
  }
}
