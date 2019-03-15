/*
 * Lab2.c
 *
 * Created: 01.02.2019 10:41:18 PM
 *  Author: asus
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
// N in ASCII: 0x4E 01001110

#define CODE_LETTER 0b01110010

void dot_secret(void)
{
	PORTC = 0x08; // green 1 
	_delay_ms(100);
	PORTC = 0x04; // 
	_delay_ms(100);
	PORTC = 0x03; //2
	_delay_ms(100);
	PORTC = 0x01; // red 1
	_delay_ms(100);
	PORTC = 0x00;
	_delay_ms(50);
}


void dot_error(void)
{
	for (int i = 0; i<10; i++)
	{
	PORTC = 0x01;
	_delay_ms(100);
	PORTC = 0x00;
	_delay_ms(50);
	}
}

void dot_reset(void)
{
	PORTC = 0x06;
	_delay_ms(500);
	PORTC = 0x00;
	_delay_ms(50);
	
}

void dash(void)
{
	PORTC = 0x07;
	_delay_ms(800);
	
	PORTC = 0x00;
	_delay_ms(50);
}

void dot_1(void)
{
	PORTC = 0x08;
	_delay_ms(100);
	PORTC = 0x00;
	_delay_ms(50);
}

void dot_0(void)
{
	PORTC = 0x01;
	_delay_ms(100);
	PORTC = 0x00;
	_delay_ms(50);
}

int main(void)
{
	DDRA = 0x0000000000; // set all as input [0000 0000]
	DDRC = 0xff; // set all as output [1111 1111]
	PORTC = 0x000000000; // [0000 0000]
	int codeLetter = 0;
	int letterCursor = 0;
	while(1)
	{
		
		if ((!(PINA & 0x1)&!(PINA & 0x2))||(!(PINA & 0x1)&!(PINA & 0x3))||(!(PINA & 0x2)&!(PINA & 0x4))||(!(PINA & 0x1)&!(PINA & 0x2)&!(PINA & 0x4)))
		{
			dot_error();
		}
		else
		{
			
		if (!(PINA & 0x1))
		{
			dot_0();
			codeLetter &= ~(1<<letterCursor);
			letterCursor++;
		}
		if (!(PINA & 0x2)) // SW1
		{
			dot_1();
			codeLetter |= (1<<letterCursor);
			letterCursor++;
		}
		if (!(PINA & 0x4)) // SW2
		{
			dot_reset();
			letterCursor = 0;
			codeLetter = 0;
		}
		if (letterCursor >= 8)
		{
			if(codeLetter == CODE_LETTER){
				dot_secret();
				}
				else{
				dot_error();
			}
			letterCursor = 0;
			codeLetter = 0;
		}
		_delay_ms(100);
		}
	}
	return 0;
}


