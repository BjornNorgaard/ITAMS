#include "switch.h"
#include <avr/io.h>
#define MAX_switch 7

void initSwitchPort(unsigned char port){
	if(port == 0){
		DDRA = 0x00;
	}
	else if(port == 1){
		DDRB = 0x00;
	}
	else if(port == 2){
		DDRC = 0x00;
	}
	else if(port == 3){
		DDRD = 0x00;
	}
}

unsigned char switchStatus(unsigned char port){
	if(port == 0){
		return ~PINA;
	}
	else if(port == 1){
		return ~PINB;
	}
	else if(port == 2){
		return ~PINC;
	}
	else if(port == 3){
		return ~PIND;
	}
}

unsigned char switchOn(unsigned char port, unsigned char switchNumber){
	if(port == 0){
		if(switchNumber <= MAX_switch){
			unsigned char mask = ~(PINA | ~(1<<switchNumber));
			return mask;
		}
	}
	else if(port == 1){
		if(switchNumber <= MAX_switch){
			unsigned char mask = ~(PINB | ~(1<<switchNumber));
			return mask;
		}
	}
	else if(port == 2){
		if(switchNumber <= MAX_switch){
			unsigned char mask = ~(PINC | ~(1<<switchNumber));
			return mask;
		}
	}
	else if(port == 3){
		if(switchNumber <= MAX_switch){
			unsigned char mask = ~(PIND | ~(1<<switchNumber));
			return mask;
		}
	}
}
