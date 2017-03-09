#include <avr/io.h>
#include "gsm_driver/gsm_driver.h"

int main(void)
{
	gsmInit();

	while (1)
	{
		gsmSendSms("24464105", "Please get this");
	}
}
