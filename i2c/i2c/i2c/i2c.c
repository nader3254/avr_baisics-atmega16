/*
 * i2c.c
 *
 * Created: 5/22/2022 11:27:34 PM
 *  Author: Nader
 */ 
#include "i2c.h"

void     spi_init(SpiDevice dev)
{
	/*  will be implemented later */
	
}
void     set_baudrate(int baud)
{
	/*  will be implemented later */
}
uint8_t  waitForTaskDone()
{
	/*  will be implemented later */
}

void TWI_start(void)
{
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // Wait till start condition is transmitted
	while((TWSR & 0xF8)!= MASTER_START_ST); // Check for the acknowledgment
	
}
void TWI_repeated_start(void)
{
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // wait till restart condition is transmitted
	while((TWSR & 0xF8)!= 0x10); // Check for the acknowledgment
	
}
void TWI_init_master(void)
{
	TWBR=0x01; // Bit rate
	TWSR=(0<<TWPS1)|(0<<TWPS0); // Setting prescalar bits
	// SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
}
void TWI_write_address(unsigned char data)
{
	TWDR=data;                    // Address and write instruction
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8)!= 0x18);  // Check for the acknowledgment
}
void TWI_read_address(unsigned char data)
{
	TWDR=data;                    // Address and read instruction
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
	while((TWSR & 0xF8)!= 0x40);  // Check for the acknowledgment
	
}
void TWI_write_data(unsigned char data)
{
	TWDR=data;                     // put data in TWDR
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != 0x28); // Check for the acknowledgment
}
unsigned char TWI_read_data(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != 0x58); // Check for the acknowledgment
	
	return TWDR;

}
void TWI_stop(void)
{
	// Clear TWI interrupt flag, Put stop condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	while(!(TWCR & (1<<TWSTO)));  // Wait till stop condition is transmitted
}


void TWI_init_slave(void)
{
	TWAR=0x20; // Fill slave address to TWAR
	
}
void TWI_match_read_slave(void)
{
	while((TWSR & 0xF8)!= 0x60)  // Loop till correct acknowledgment have been received
	{
		// Get acknowledgment, Enable TWI, Clear TWI interrupt flag
		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
	}
}
char TWI_read_slave(void)
{
	// Clear TWI interrupt flag,Get acknowledgment, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT))); // Wait for TWINT flag
	while((TWSR & 0xF8)!=0x80); // Wait for acknowledgment
	return TWDR; // Get value from TWDR
	
	
}
void TWI_match_write_slave(void)
{
	while((TWSR & 0xF8)!= 0xA8) // Loop till correct acknowledgment have been received
	{
		// Get acknowledgment, Enable TWI, Clear TWI interrupt flag
		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
	}
	
}
void TWI_write_slave(char data)
{
	TWDR= data;           // Fill TWDR register with the data to be sent
	TWCR= (1<<TWEN)|(1<<TWINT);   // Enable TWI, Clear TWI interrupt flag
	while((TWSR & 0xF8) != 0xC0); // Wait for the acknowledgment
	
}

