#include "gsm_driver.h"
#include "uart.h"

#define F_CPU 3868400
#include <util/delay.h>

const char CR = 13;
const char CTRL_Z = 26;

void gsmInit()
{
	gsmSetEcho(1);
	gsmSetTextMode();
	gsmConfigSms();
}

void gsmSendSms(char* phonenumber, char* message)
{
	uartSendString("AT+CMGS=");
	uartSendString(phonenumber);
	uartSendChar(CR);

	while(uartReadChar() != '>') { }
	_delay_ms(200);

	uartSendString(message);
	uartSendChar(CTRL_Z);

	gsmWaitForResponse();
}

void gsmWaitForResponse()
{
	while(1)
	{
		if (uartReadChar() == 'K')
		{
			break;
		}
		else if (uartReadChar() == 'E')
		{
			break;
		}
	}

	_delay_ms(200);
}

void gsmSetEcho(char echo)
{
	uartSendString("ATE");
	uartSendChar(echo);
	uartSendString("\r");

	gsmWaitForResponse();
}

void gsmSetTextMode()
{
	uartSendString("AT+CMGF=1");
	uartSendString("\r");

	gsmWaitForResponse();
}

void gsmConfigSms()
{
	uartSendString("AT+CNMI=3,1\r");

	gsmWaitForResponse();
}
