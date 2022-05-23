/*
 * i2c.c
 *
 * Created: 5/22/2022 8:59:55 PM
 * Author : Nader
 */ 

#include <avr/io.h>
#include "i2c.h"

int main(void)
{
	TWI_init_master();  // Function to initialize TWI
	TWI_init_slave(); // Function to initialize slave
	
	
    while (1) 
    {
		TWI_start(); // Function to send start condition
		TWI_write_address('a'); // Function to write address and data direction bit(write) on SDA
		TWI_write_data('b');      // Function to write data in slave
		TWI_stop(); // Function to send stop condition
		
		
		
		TWI_match_read_slave(); //Function to match the slave address and slave direction bit(read)
		TWI_read_slave(); // Function to read data
		TWI_match_write_slave(); //Function to match the slave address and slave direction bit(write)
		TWI_write_slave('x');       // Function to write data
    }
}

