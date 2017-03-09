#include "gsm_driver.h"
#include "uart.h"

#define F_CPU 3868400
#include <util/delay.h>

void gsmInit()
{
	gsmSetEcho(1);
	gsmSetTextMode();
	gsmConfigSms();
}

void gsmWaitForResponse()
{
	_delay_ms(210);
}

void gsmSetEcho(unsigned char echo)
{
	uartSendString("ATE");
	uartSendString(echo);
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
