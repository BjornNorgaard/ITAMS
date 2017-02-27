/**************************************
* "uart.h":                           *
* Header file for Mega32 UART driver. *
* Henning Hargaard, 1/11 2011         *
***************************************/
void initUart(unsigned long baudRate, unsigned char dataBit);
unsigned char charReady();
char readChar();
void sendChar(char charToSend);
void sendString(char* stringToSend);
void sendInteger(int number);
/**************************************/
