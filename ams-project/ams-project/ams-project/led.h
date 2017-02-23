
void initLEDport(unsigned char port); /* 
0 = PORTA, 1 = PORTB, 2 = PORTC, 3 = PORTD
*/

void writeAllLEDs(unsigned char port, unsigned char pattern);/*
port: 0=A, 1=B...
pattern: the pattern for show.
*/

void turnOnLED(unsigned char port, unsigned char led);/*
port: 0=A, 1=B...
led: the LED to turn on.
*/

void turnOffLED(unsigned char port, unsigned char led);/*
port: 0=A, 1=B ...
led: the LED to turn off.
*/

void toggleLED(unsigned char port, unsigned char led);/*
port: 0=A, 1=B...
led: the LED to toggle.
*/
