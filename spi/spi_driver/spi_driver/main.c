/*
 * spi_driver.c
 *
 * Created: 5/19/2022 3:56:48 PM
 * Author : Nader
 */ 

#include <avr/io.h>
#include "spi.h"
#define F_CPU 8000000UL

int main(void)
{
    spi_init(spi_master,8);
	unsigned char frame[]={35,32,1,0,8,19};
    while (1) 
    {
		spi_send_string("hello from atmega16");
		//spi_send_frame(frame);      
		//spi_send_byte('A');
		//char x       = spi_recieve_byte();
		//char frame[] = spi_recieve_frame(6);
		char* str      = spi_recieve_string();

    }
}

