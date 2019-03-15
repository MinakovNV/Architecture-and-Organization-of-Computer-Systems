/*
 * Lab1.c
 *
 * Created: 24.01.2019 10:01:19 PM
 *  Author: asus.venik
 */ 



#include <avr/io.h>
#include <util/delay.h>


/*
void delay(uint16_t time)
{
	while(time>1)
	{
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		time--;
	}
}
*/

void dot(void)
{
	_delay_ms(10);
	PORTB=0b00000001; // 1
	_delay_ms(10);
	PORTB=0b00000000;
}

void dashe(void)
{
	_delay_ms(10);
	PORTB=0b00000001; //1
	_delay_ms(10);
	PORTB=0b00000000;
}

void pause(void)
{
	_delay_ms(10);
	_delay_ms(10);
}

void dot1(void)
{
	_delay_ms(10);
	PORTB=0b00000010; // 1
	_delay_ms(10);
	PORTB=0b00000000;
}

void dashe1(void)
{
	_delay_ms(10);
	PORTB=0b00000010; //1
	_delay_ms(10);
	PORTB=0b00000000;
}

int main(void)
{
	
	
	DDRB=0b00000011;
	PORTB=0b00000000;
	while(1)
	{
		//FIRST NAME
		// letter N-..
		dashe();
		dot();
		pause();

		//letter I -..
		dot1();
		dot1();
		//pause();
		
		//letter K -..
		dashe();
		dot();
		dashe();
		//pause();
		
		//letter I -..
		dot1();
		dot1();
		//pause();
		
		//letter T -..
		dashe();
		//pause();
		
		// letter A-..
		dot1();
		dashe1();
		//pause();
		
	}
	return 0;
}


