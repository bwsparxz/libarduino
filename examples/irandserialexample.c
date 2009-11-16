/********************************************************************
* libarduino example
********************************************************************/
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "libarduino.h"

int main (void)
{
	uint8_t c;

	serial_init();
	fdevopen(serial_putchar, serial_getchar);

	ir_init();

	sei(); /* enable interrupts */

	while (1)
	{
		c = ir_get();
		printf("got ir cmd %d\n\r", c);
	}

	return 1;
}