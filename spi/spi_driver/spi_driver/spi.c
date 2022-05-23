/*
 * spi.c
 *
 * Created: 5/19/2022 4:15:39 PM
 *  Author: Nader
 */ 
#include "spi.h"

void spi_init(spi_mode_data_type mode,uint8_t frequencydivider)
{
	switch(mode)
	{
		case spi_master:
		           
		/* Set MOSI and SCK output,SS all others input */
				  DDRB |= (1<<PB5)|(1<<PB7)|(1<<PB4);  
	   /* Enable SPI, Master, set clock rate fck/16 */
				   SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
                				
		    break;
		case spi_slave:
		/* Set MISO output, all others input */
		        DDRB = (1<<PB6);
		  /* Enable SPI */
		       SPCR = (1<<SPE);
            break;
	}
	/*OPTIONAL*/
	SPCR |= (1<<CPOL);    //falling edge triggered
	
	/* set the clock speed */
	switch(frequencydivider)
	{
		case 4:              
		break;
		case 16:   SPCR |= (1<<SPR0);
		break;
		case 64:   SPCR |= (1<<SPR1);
		break;
		case 128:  SPCR |=  (1<<SPR0) |(1<<SPR1) ;
		break;
		
		case 2:
		break;
		case 8:    SPCR |= (1<<SPR0);   SPSR |= (1<<SPI2X);
		break;
		case 32:   SPCR |= (1<<SPR1);   SPSR |= (1<<SPI2X);
		break;
		
       
	   default:
	   break;
		
	}
	
	
}


void spi_send_byte(unsigned char temp)
{
	/* Start transmission */
	SPDR = temp;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
	
	
}
void spi_send_frame(unsigned char buffer[])
{
	for (int i=0 ; buffer[i]!='\0' ;i++)
	{
		/* Start transmission */
		SPDR = buffer[i];
		/* Wait for transmission complete */
		while(!(SPSR & (1<<SPIF)))
		;
		
	}
	
	
}
void spi_send_string(char * text)
{
	uint8_t i=0;
	while(text !='\0')
	{
			/* Start transmission */
			SPDR = text[i] ;
			i++;
			/* Wait for transmission complete */
			while(!(SPSR & (1<<SPIF)))
			;
	}
	
}

unsigned char   spi_recieve_byte()
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
	return SPDR;
	
}
unsigned char* spi_recieve_frame(int frame_size)
{
	unsigned char temp[frame_size];
	for (int i=0;i<frame_size;i++)
	{
			/* Wait for reception complete */
			while(!(SPSR & (1<<SPIF)));
			/* Return data register */
			temp[i] = SPDR;
	}
	return temp;
	
}
/*********************************************************************/
/* will be implemented later */
/********************************************************************/
char*  spi_recieve_string()
{
	
	return "string default";
	
}