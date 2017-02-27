#include <avr/io.h>
#include "led.h"
#define MAX_led 7

void initLedPort(unsigned char port){
	if (port == 0){
		DDRA = 0xFF;	// 1 for OUTPUT
		PORTC = 0xFF;	// LEDs slukket
	}
	else if (port == 1){
		DDRB = 0xFF;
		PORTB = 0xFF;
	}
	else if (port == 2){
		DDRC = 0xFF;
		PORTC = 0xFF;
	}
	else if (port == 3){
		DDRD = 0xFF;
		PORTD = 0xFF;
	}
}

void writeAllLeds(unsigned char port, unsigned char pattern){
	if(port == 0){
		PORTA = ~pattern;
	}
	else if(port == 1){
		PORTB = ~pattern;
	}
	else if(port == 2){
		PORTC = ~pattern;
	}
	else if(port == 3){
		PORTD = ~pattern;
	}
}

void turnOnLed(unsigned char port, unsigned char led){
	unsigned char mask;
	
	if(port == 0){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTA = PINA & mask;
		}
	}
	if(port == 1){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTB = PINB & mask;
		}
	}
	if(port == 2){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTC = PINC & mask;
		}
	}
	if(port == 3){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTD = PIND & mask;
		}
	}
}

void turnOffLed(unsigned char port, unsigned char led){
	unsigned char mask;
	
	if(port == 0){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTA = PINA | mask;
		}
	}
	if(port == 1){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTB = PINB | mask;
		}
	}
	if(port == 2){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTC = PINC | mask;
		}
	}
	if(port == 3){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTD = PIND | mask;
		}
	}
}

void toggleLed(unsigned char port, unsigned char led){
	unsigned char mask;
	
	if(port == 0){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTA = PINA ^ mask;
		}
	}
	if(port == 1){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTB = PINB ^ mask;
		}
	}
	if(port == 2){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTC = PINC ^ mask;
		}
	}
	if(port == 3){
		if (led <= MAX_led)
		{
			mask = ~(0b00000001 << led);
			PORTD = PIND ^ mask;
		}
	}
}
