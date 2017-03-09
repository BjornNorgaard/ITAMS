#include "gsm_driver.h"
#include "uart.h"

#define F_CPU 3868400
#include <util/delay.h>

const char CR = 13;
const char CTRL_Z = 26;

void gsmInit()
{
	gsmSetEcho(0);
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
	char * errorMsg = "ERROR";
	int pointer = 0;
	char received = 0;
	char previous = 0;
	
	while ((received = uartReadChar()) != 0)
	{
		if (previous == 'O' && received == 'K')
		{
			uartReadChar();
			uartReadChar();
			break;
		}
		else
		{
			previous = received;
		}
		
		if (received == errorMsg[pointer])
		{
			pointer++;
		}
		else
		{
			pointer = 0;
		}
		
		if (pointer >= 5)
		{
			uartReadChar();
			uartReadChar();
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
	uartSendString("AT+CMGF=1\r");

	gsmWaitForResponse();
}

void gsmConfigSms()
{
	uartSendString("AT+CNMI=3,1\r");

	gsmWaitForResponse();
}
