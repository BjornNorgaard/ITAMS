#include <avr/io.h>
#include "gsm_driver/gsm_driver.h"

#define F_CPU 3868400
#include <util/delay.h>

int main(void)
{
	gsmInit();

	while (1)
	{
		gsmSendSms("24464105", "Please get this");
		_delay_ms(1000);
	}
}
