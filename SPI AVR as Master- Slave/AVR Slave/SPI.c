
//Initialize SPI Master Device
void spi_init_master (void)            
{
	DDRB |= (1<<5)|(1<<7)|(1<<4);			// Make MOSI, SCK, SS as Output pin 
	DDRB &= ~(1<<6);						// Make MISO pin as input pin 
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	// Enable SPI in master mode with Fosc/16 
	SPSR &= ~(1<<SPI2X);					// Disable speed doubler 
}


//Initialize SPI Slave Device
void spi_init_slave (void)
{
    DDRB=(1<<6);                           //MISO as OUTPUT
    SPCR=(1<<SPE);                         //Enable SPI
}


//Function to send data
unsigned char SPI_MasterTransmit(unsigned char cData)
{
	char flush_buffer;
	SPDR = cData;							// Write data to SPI data register
	while(!(SPSR & (1<<SPIF)));			// Wait till transmission complete
	flush_buffer = SPDR;					// Flush received data
}


//Function to receive data
unsigned char SPI_SlaveReceive(void)
{

	while(!(SPSR & (1<<SPIF)));			// Wait for reception complete
	return(SPDR);							// Return data register
}


//Function to send and receive data
unsigned char spi_tranceiver (unsigned char data)
{
    SPDR = data;                       		//Load data into the buffer
    while(!(SPSR)&(1<<SPIF));         		//Wait until transmission complete
    return(SPDR);                      		//Return received data
}
