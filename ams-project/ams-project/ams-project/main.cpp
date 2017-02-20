#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch"
#include "uart.h"

#define CTRL_Z 26

void SendMessage(char* message, char* phonenumber);

int main(void)
{
	InitUART(9600, 8);
	initLEDport(2);

	char message[50] = "Hello world!";
	char phonenumber[11] = "+4513371337";

	/* Replace with your application code */
	while (1)
	{
		SendMessage(message, phonenumber);
		_delay_ms(5000);
	}
}


void SendMessage(char* message, char* phonenumber)
{
	SendString("AT+CMGS=");
	SendString(phonenumber);
	SendString(message);
	SendChar(CTRL_Z);
}