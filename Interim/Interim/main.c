/*
 * Interim.c
 *
 * Created: 7/24/2019 5:23:21 PM
 * Author : Anuththara
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#define D0 eS_PORTD0
#define D1 eS_PORTD1
#define D2 eS_PORTD2
#define D3 eS_PORTD3
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"


char numberpressed();

int main(void)
{
  
	/*DDRB = 0xF0;
	DDRD = 0xFF;
	DDRC = 0xFF;
	DDRA = 0xFF;*/
	
	DDRB = 0xFF;
	
	PORTB = 0x00;
	
	/*Lcd8_Init();
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,0);
	Lcd8_Write_String(" Welcome");
	Lcd8_Set_Cursor(2,0);
	Lcd8_Write_String(" Level 1");
	_delay_ms(500);
	
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,0);
	Lcd8_Write_String(" Initializing..");
	
	PORTA = 0xFF;
	_delay_ms(500);
	PORTA = 0x00;
	
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,0);
	Lcd8_Write_String(" Bulb 01");
	PORTA = 0x01;
	_delay_ms(500);
	
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,0);
	Lcd8_Write_String(" Bulb 02");
	PORTA = 0x02;
	_delay_ms(500);
	
	
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,0);
	Lcd8_Write_String(" Bulb 03");
	PORTA = 0x04;
	_delay_ms(500);*/
  
    while (1) 
    {
		/*Lcd8_Clear();
		Lcd8_Set_Cursor(1,0);
		char c = numberpressed();
		if(c == '1'){
			PORTA = 0x01;
			Lcd8_Write_String(" Pressed 1");
		}else if(c == '2'){
			PORTA = 0x02;
			Lcd8_Write_String(" Pressed 2");
		}
		else if(c == '3'){
			PORTA = 0x04;
			Lcd8_Write_String(" Pressed 3");
		}else{
			
		}
		_delay_ms(2000);*/
		
		/*char c = numberpressed();
		
		if(c == '1')
			PORTA = 0b00000010;
		else if(c == '2')		
			PORTA = 0b00000010;
		else if(c == '3')
			PORTA = 0b00000100;
		else if(c == '4')
			PORTA = 0b00010000;
		else
			PORTA = 0b00000000;
		_delay_ms(500);*/
		
		PORTB = 0x01;
		_delay_ms(2000);
		PORTB = 0x00;
		_delay_ms(2000);
    }
}

char numberpressed()
{
	PORTB = 0b10000000;
	if(PINB & (1<<PB0))
	{
		return 'a';
	}
	if(PINB & (1<<PB1))
	{
		return '3';
	}
	if(PINB & (1<<PB2))
	{
		return '2';
	}
	if(PINB & (1<<PB3))
	{
		return '1';
	}
	
	PORTB = 0b01000000;
	if(PINB & (1<<PB0))
	{
		return 'b';
	}
	if(PINB & (1<<PB1))
	{
		return '6';
	}
	if(PINB & (1<<PB2))
	{
		return '5';
	}
	if(PINB & (1<<PB3))
	{
		return '4';
	}
	PORTB = 0b00100000;
	if(PINB & (1<<PB0))
	{
		return 'c';
	}
	if(PINB & (1<<PB1))
	{
		return '9';
	}
	if(PINB & (1<<PB2))
	{
		return '8';
	}
	if(PINB & (1<<PB3))
	{
		return '7';
	}
	PORTB = 0b00010000;
	if(PINB & (1<<PB0))
	{
		return 'd';
	}
	if(PINB & (1<<PB1))
	{
		return '#';
	}
	if(PINB & (1<<PB2))
	{
		return '0';
	}
	if(PINB & (1<<PB3))
	{
		return '*';
	}
}


