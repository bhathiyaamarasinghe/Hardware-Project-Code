/*
 * Final Project.c
 *
 * Created: 7/30/2019 12:58:05 PM
 * Author : Anuththara
 */ 

#define F_CPU 1000000UL


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
void startBlender(); 
void stopBlender();
void startWaterPump();
void stopWaterPump();
void stopBlender();
void startOilPump();
void stopOilPump();
void startMixturePump();
void stopMixturePump();
void coilheat();
void coilcool();
void servoUp();
void servoDown();
void coilTwoheat();
void coilTwocool();
void motorUp();
void motorDown();
void delay(int n);

int main(void)
{
    DDRB = 0xF0;
	DDRD = 0xFF;
	DDRC = 0xFF;
	DDRA = 0xFF;
	

	
	stopBlender();
	stopWaterPump();
	stopOilPump();
	stopMixturePump();
	coilcool();
	coilTwocool();
	//PORTA &= ~(1<<PA1);

	
	char c;
	//int i;
	
	Lcd8_Init();
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,0);
	Lcd8_Write_String(" Welcome.... ");
	Lcd8_Set_Cursor(1,17);
	Lcd8_Write_String(" -Level 1- ");
	Lcd8_Set_Cursor(2,0);
	Lcd8_Write_String("Hardware Project ");
	Lcd8_Set_Cursor(2,17);
	Lcd8_Write_String(" Group No.09 ");
	delay(10);
	
	
    while (1) 
    {
		Lcd8_Clear();
		Lcd8_Set_Cursor(1,0);
		Lcd8_Write_String("Press to start");
		delay(2);
		
		while(1){
			c = numberpressed();
			if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8'  || c == '9'  || c == '*'  || c == '#'){
				//start blendering
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Start blender");
				startBlender();
				delay(30);
			    //stop blendering
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Stop blender");
				stopBlender();
				delay(5);
				//start waterpump
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Start water pump");
				startWaterPump();
				delay(10);
				//stop waterpump
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Stop water pump");
				stopWaterPump();
				delay(20);
				//start blendering
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Start blender");
				startBlender();
				delay(30);
				 //stop blendering
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Stop blender");
				stopBlender();
				delay(5);
				//start oil pump
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Start oil pump");
				startOilPump();
				delay(10);
				//stop oil pump
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Stop oil pump");
				stopOilPump();
				delay(20);
				//falling mixture to hotplate:1
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("h.p-1 heat");
				coilheat();
				delay(20);
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("h.p-1 cool");
				coilcool();
				delay(20);
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("mixture to h.p:1");
				startMixturePump();
				delay(10);
				//stop falling mixture to hotplate:1
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("mixture to h.p:1");
				stopMixturePump();
				delay(5);
				//hotplate:1 heating
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("h.p-1 heat");
				coilheat();
				delay(20);
			    //hotplate:1 cooling
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("h.p-1 cool");
				coilcool();
				delay(20);
				//servo:1 turning
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Servo:1 Up");
				servoUp();
				delay(5);
				//servo:1 turn return
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Servo:1 Down");
				servoDown();
				delay(5);
				//hotplate:2 heating
				Lcd8_Clear();
	            Lcd8_Set_Cursor(1,0);
	            Lcd8_Write_String("h.p-2 heat");
	            coilTwoheat();
	            delay(20);
				//hotplate:2 cooling	
				Lcd8_Clear();	
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("h.p-2 cool");
				coilTwocool();
				delay(20);
				//servo:2 turning
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Servo:2 up");
				motorUp();
				delay(5);
				//servo:2 turn return
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Servo:2 Down");
				motorDown();
				delay(5);
				break;
			}
		}
    }
}

void delay(int n){
	int i;
	for(i = 0; i < n ; i++){
		_delay_ms(1000);
	}
}

//DC start
void startBlender(){
	PORTA &= ~(1<<PA2);
	_delay_ms(1000);
	
}

//DC stop
void stopBlender(){
	PORTA |= (1<<PA2);
	_delay_ms(100);
	
}

//pump:1 start
void startWaterPump(){
	PORTA &= ~(1<<PA3);
	_delay_ms(10);
	
}
//pump:1 stop
void stopWaterPump(){
	PORTA |= (1<<PA3);
	_delay_ms(100);
	
}

//pump:2 start
void startOilPump(){
	PORTA &= ~(1<<PA4);
	_delay_ms(2);
}
//pump:2 stop
void stopOilPump(){
	PORTA |= (1<<PA4);
	_delay_ms(10);
	
}
//pump:3 start
void startMixturePump(){
	PORTA &= ~(1<<PA5);
	_delay_ms(8);
	
}
//pump:3 stop
void stopMixturePump(){
	PORTA |= (1<<PA5);
	_delay_ms(100);
	
}
//coil:1 heat
void coilheat(){
	PORTA &= ~(1<<PA6);
	_delay_ms(40000);
	
}

//coil:1 cool
void coilcool(){
	PORTA |= (1<<PA6);
	_delay_ms(100);
	
	
}


//servo:1 up
void servoUp(){
	int i;
	for(i=0;i<40;i++){
		PORTA = 0b11111101;
		_delay_ms(2);
		PORTA = 0b11111100;
		_delay_ms(18);
	}
}

//servo:1 down
void servoDown(){
	int i;
	for(i=0;i<40;i++){
		PORTA = 0b11111101;
		_delay_ms(1);
		PORTA = 0b11111100;
		_delay_ms(19);
	
	}
}

//coil:1 heat
void coilTwoheat(){
	PORTA &= ~(1<<PA7);
	_delay_ms(10000);
	
}

//coil:1 cool
void coilTwocool(){
	PORTA |= (1<<PA7);
	_delay_ms(1000);
	
}

//servo:1 up
void motorUp(){
	int i;
	for(i=0;i<40;i++){
		PORTA = 0b11111110;
		_delay_ms(2);
		PORTA = 0b11111100;
		_delay_ms(18);
	}
}

//servo:1 down
void motorDown(){
	int i;
	for(i=0;i<40;i++){
		PORTA = 0b11111110;
		_delay_ms(1);
		PORTA = 0b11111100;
		_delay_ms(19);
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



