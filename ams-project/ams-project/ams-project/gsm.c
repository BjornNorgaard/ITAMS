#include "gsm.h"
#include "uart.h"

#define CTRL_Z 26

void sendMessage(char* phonenumber, char* message) {
	sendString("AT+CMGS=");
	sendString(phonenumber);
	sendString("\r\n");
	sendString(message);
	sendChar(CTRL_Z);
}
