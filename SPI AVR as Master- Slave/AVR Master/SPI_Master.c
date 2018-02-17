
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <compat/deprecated.h>

#include "SPI.c"

int main(void)
{
    spi_init_master();                  //Initialize SPI Master

    uint8_t x = 0;                      //Counter value which is sent
    
    while(1)
    {

	cbi(PORTB,4);
	SPI_MasterTransmit(x++);
	sbi(PORTB,4);
	
		if(x > 126)
		{
			x=0;
		}

	_delay_ms(500);

    }
}
