#include "gsm.h"
#include "uart.h"

#define CTRL_Z 26

void sendMessage(char* phonenumber, char* message) {
	SendString("AT+CMGS=");
	SendString(phonenumber);
	SendString("\r\n");
	SendString(message);
	SendChar(CTRL_Z);
}
