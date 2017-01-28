/*
 * EXAMPLE.cpp
 * GNU Public License
 * Created: 25/1/2017
 * Author: Moshtak ALLAH
 */ 
#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "SEVEN_SEG.h"

SEVEN_SEG sevenanode = SEVEN_SEG(COMMON_ANODE, makePort(PORTD),0,1,2,3,4,5,6,7);
SEVEN_SEG sevencathode = SEVEN_SEG(COMMON_CATHODE, makePort(PORTB),6,5,4,3,2,1,0 );
SEVEN_SEG seven7447(COMMON_ANODE,makePort(PORTC), 1,2,3,4);

int main(void)
{ 
    
	sevenanode.ledtest();
	sevencathode.ledtest();
	_delay_ms(2000);

    while (1)
	{  
		sevenanode.setPoint();
		
		for(char i=0;i<10;i++){
			sevenanode.print(i);
			sevencathode.print(i);
			seven7447.print(i);
		   _delay_ms(500);
		}
		
		sevenanode.clear();
		sevenanode.clearPoint();
		sevencathode.clear();
		_delay_ms(1000);
		sevenanode.print('A');
		sevencathode.print('F');
		_delay_ms(1000);
		
    }
}

