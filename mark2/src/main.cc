#include <avr/io.h>
#include <util/delay.h>

void forward()
{
  PORTC &= ~(1 << 1 | 1 << 4);
  PORTC |= (1 << 0 | 1 << 3 );
}

void backward()
{
  PORTC |= (1 << 1 | 1 << 4);
  PORTC &= ~(1 << 0 | 1 << 3 );
}

void stop()
{
  PORTC &= ~(1 << 0 | 1 << 1 | 1 << 3 | 1 << 4);
}

void right()
{

}

void left(){

}

int main (void)
{
  // set PORTc 0-5 as output
  DDRC = 0x1F;
  DDRD = 0x00;
  PORTD = 0xFF;

  PORTC = 0xff;//1 << 2 | 1 << 5;
  while(1) 
  {
    if(((PIND >> 5) & 1) == 0) {
      forward();
    } else if ((PIND & (1 << 6)) == 0) {
      backward();
    } else {
      stop();
    }
  }
}