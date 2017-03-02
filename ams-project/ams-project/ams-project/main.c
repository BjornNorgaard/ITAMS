#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"
#include "uart.h"
#include "gsm.h"

#define led_port 2
#define switch_port 1

int main(void)
{
	initLedPort(led_port);
	initSwitchPort(switch_port);
	initUart(9600, 8);
	
	char message[50] = "Helloworld!";
	char phonenumber[20] = "+4524464105";

	sendMessage(phonenumber, message);

	while (1)
	{
		for (int i = 0; i < 8; i ++)
		{
			toggleLed(led_port, i);
			_delay_ms(100);
		}
		_delay_ms(500);
	}
}
