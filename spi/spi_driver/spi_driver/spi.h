/*
 * spi.h
 *
 * Created: 5/19/2022 4:15:20 PM
 *  Author: Nader
 */ 


#ifndef SPI_H_
#define SPI_H_

#include<avr/io.h>
#include<util/delay.h>

typedef enum 
{
	spi_master,
	spi_slave
	
}spi_mode_data_type;



void spi_init(spi_mode_data_type mode ,uint8_t frequencydivider);


void spi_send_byte(unsigned char temp);
void spi_send_frame(unsigned char buffer[]);
void spi_send_string(char * text);

unsigned char   spi_recieve_byte();
unsigned char* spi_recieve_frame(int frame_size);
char*           spi_recieve_string();


#endif /* SPI_H_ */