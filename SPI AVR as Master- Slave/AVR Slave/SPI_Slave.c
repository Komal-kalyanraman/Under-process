
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <compat/deprecated.h>

#include <lib_uart.c>
#include <lib_uart.h> 

#include "SPI.c"

int main(void)
{
    spi_init_slave();                             //Initialize slave SPI
    
    unsigned char data, send, buffer[10];

    DDRB |= (1 << PB0);
	DDRB |= (1 << PB1);
	
	cbi(PORTB,0);
	sbi(PORTB,1);
    
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
    
	while(1)
    {

        data = SPI_SlaveReceive();
		itoa(data, buffer, 10);                   //Convert integer into string
		
		uart_puts(buffer);
		uart_puts("\n");
		uart_puts("\r");
		
		if(data == 126)
		{
			// toggle the LED
			PORTB ^= 1 << PB0;
			PORTB ^= 1 << PB1;
		}
    }
}

