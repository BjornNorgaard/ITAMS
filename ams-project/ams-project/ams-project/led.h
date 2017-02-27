
void initLedPort(unsigned char port); /* 
0 = PORTA, 1 = PORTB, 2 = PORTC, 3 = PORTD
*/

void writeAllLeds(unsigned char port, unsigned char pattern);/*
port: 0=A, 1=B...
pattern: the pattern for show.
*/

void turnOnLed(unsigned char port, unsigned char led);/*
port: 0=A, 1=B...
led: the LED to turn on.
*/

void turnOffLed(unsigned char port, unsigned char led);/*
port: 0=A, 1=B ...
led: the LED to turn off.
*/

void toggleLed(unsigned char port, unsigned char led);/*
port: 0=A, 1=B...
led: the LED to toggle.
*/
