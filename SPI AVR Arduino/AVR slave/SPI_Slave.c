
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <compat/deprecated.h>


#include "SPI.c"

int main(void)
{
    spi_init_slave();                             //Initialize slave SPI
    
    unsigned char data, send, buffer[10];
    
	// PB0 = output (LED)
    DDRB |= (1 << PB0);
	DDRB |= (1 << PB1);
	
	cbi(PORTB,0);
	sbi(PORTB,1);
    
    while(1)
    {
		send = data;
		
        data = spi_tranceiver(send);
        itoa(data, buffer, 10);                   //Convert integer into string
		if(data == 126)
		{
			// toggle the LED
			PORTB ^= 1 << PB0;
			PORTB ^= 1 << PB1;
		}
    }
}
