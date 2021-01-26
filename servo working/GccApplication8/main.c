/*
 * GccApplication8.c
 *
 * Created: 7/24/2019 10:46:17 AM
 * Author : Bhathiya
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA = 0xFF;
	
	PORTA = 0x00;

	int i;
	
		for(i=0;i<40;i++){
			PORTA = 0x01;
			_delay_ms(2);
			PORTA = 0x00;
			_delay_ms(18);
		}
		
		
		
	
	
	
	for(i=0;i<40;i++){
		PORTA = 0x01;
		_delay_ms(1);
		PORTA = 0x00;
		_delay_ms(19);
	}
	
}

