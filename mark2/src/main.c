#include <avr/io.h>
#include <util/delay.h>

intmain (void)
{
  DDRB |= _BV(DDB0); 
  
  while(1) 
  {
    PORTB ^= _BV(PB0);
    _delay_ms(500);
  }
}