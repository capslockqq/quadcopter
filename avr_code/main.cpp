#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{

  DDRB = 0xFF; //Nakes PORTC as Output
  while(1) //infinite loop
  {
    _delay_ms(100);
    PORTB = 0xFF; //Turns ON All LEDs
    _delay_ms(100);
    PORTB = 0x00; //Turns ON All LEDs

    
  }
}
