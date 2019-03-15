/*
 * Lab3.c
 *
 * Created: 28.02.2019 4:30:21 PM
 *  Author: asus.venik
 */ 

#include <avr/io.h>

// face correct pvm

#define F_CPU 1000000UL

#include <util/delay.h>

void pwm_init()
{
// initialize timer0 in PWM mode
	TCCR0A |= (1<<WGM00)|(1<<COM0A1)|(1<<WGM01);// WGM:биты, частота //COM:полярность напряжения 
	TCCR0B |= (1<<CS00);// частота работы PVM с микроконтроллером // no prescaling
	PORTB = 0b10000000;
// make sure to make OC0 pin as output pin
}

int main(void) {

/* Replace with your application code */

	DDRA = 0x00;
	DDRB = 0b10000000;
	pwm_init();
	OCR0A = 0x00;
	
	while (1){

	if (!(PINA & 0x1)){
		if (OCR0A>250){
			OCR0A = 0x00;
		} else {
		OCR0A += 50;
		_delay_ms(200);
			}
		}
	}
}

