

#define ACK 0x7E

//Initialize SPI Master Device
void spi_init_master (void)            
{
    DDRB = (1<<5)|(1<<3);              //Set MOSI, SCK as Output
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); //Enable SPI, Set as Master
                                       //Prescaler: Fosc/16, Enable Interrupts
}


//Initialize SPI Slave Device
void spi_init_slave (void)
{
    DDRB=(1<<6);                                  //MISO as OUTPUT
    SPCR=(1<<SPE);                                //Enable SPI
}

//Function to send and receive data
unsigned char spi_tranceiver (unsigned char data)
{
    SPDR = data;                       //Load data into the buffer
    while(!(SPSR)&(1<<SPIF));          //Wait until transmission complete
    return(SPDR);                      //Return received data
}