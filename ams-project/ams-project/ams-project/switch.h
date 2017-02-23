
void initSwitchPort(unsigned char port); /*
port: 0=A, 1=B ...
*/

unsigned char switchStatus(unsigned char port); /*
port: 0=A, 1=B ...
returns status of switches on the choosen port.
*/

unsigned char switchOn(unsigned char port, unsigned char switchNumber);/*
port: 0=A, 1=B ...
turns the switch on.
*/
