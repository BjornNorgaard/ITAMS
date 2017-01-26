#define F_CPU 3686400UL
#include <avr/io.h>
#include <util/delay.h>

#define PAUSE _delay_ms(50)

int main(void)
{
	DDRC = 0xFF;

	while (1)
	{
		PORTC = 0x00;
		PAUSE;
		PORTC = 0xFF;
		PAUSE;
	}
}
