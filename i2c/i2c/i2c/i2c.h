/*
 * i2c.h
 *
 * Created: 5/22/2022 11:27:15 PM
 *  Author: Nader
 */ 

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include <time.h>



/**********************************************************************************************
                           S T A T U S        D E F I N I T I O N S
***********************************************************************************************/
#define  MASTER_START_ST         0x08                /* master start signal status   */ 
#define  MASTER_RSTART_ST         0x08                /* master repeted start signal status   */ 
#define  MTX_ADRESS_ACK_ST       0x18                /* master transmitter address reacknowledgment  */        
#define  MTX_DATA_ACK_ST         0x28                /* master transmitter data reacknowledgment  */ 
#define  MRX_ADERSS_ACK_ST       0x40                /* master receiver address reacknowledgment  */ 
#define  MRX_DATA_ACK_ST         0x50                /* master receiver address reacknowledgment  */ 

#define  SRX_ADRESS_ACK_ST       0x60                /* slave receiver address acknowledgment  */ 
#define  SRX_DATA_ACK_ST         0x80                /* slave receiver data acknowledgments  */ 
#define  STX_ADRESS_ACK_ST       0xa8                /* slave transmitter address acknowledgments  */ 
#define  STX_DATA_ACK_ST         0xb8                /* slave transmitter address acknowledgments  */ 

//cloned from page 197 in the data sheet

typedef enum  
{
	masterRX , masterTX,
	slaveRX  , slaveTX
}SpiModeType;

typedef struct  
{
	SpiModeType   mode;
	int           baudrate      ;
	int           DeviceAddress ;
	
}SpiDevice;

void     spi_init(SpiDevice dev);
void     set_baudrate(int baud);
uint8_t  waitForTaskDone();

void TWI_start(void);
void TWI_repeated_start(void);
void TWI_init_master(void);
void TWI_write_address(unsigned char data);
void TWI_read_address(unsigned char);
void TWI_write_data(unsigned char);
unsigned char TWI_read_data(void);
void TWI_stop(void);


void TWI_init_slave(void);
void TWI_match_read_slave(void);
char TWI_read_slave(void);
void TWI_match_write_slave(void);
void TWI_write_slave(char data);


















#endif /* I2C_H_ */