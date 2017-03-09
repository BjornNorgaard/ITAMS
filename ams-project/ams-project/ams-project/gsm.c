#include "gsm.h"
#include "uart.h"

#define CTRL_Z 26

void setTextMode() {
	sendString("AT+CMGF=1");
	sendString("\r\n");
}

void disableEcho() {
	sendString("ATE0");
}

void sendMessage(char* phonenumber, char* message) {
	setTextMode();

	sendString("AT+CMGS=");
	sendString(phonenumber);
	sendString("\r\n");
	sendString(message);

	sendChar(CTRL_Z);
}

void getMessages(char* mailbox) {
	sendString("AT+CMGL=ALL");

	char recieved[200];
	while(charReady())
	{
		readChar();
	}
}
