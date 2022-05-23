#include "power_reset_config.h"

void power_mode(uint8_t x)
{
	MCUCR |=(1<<SE);	
	for (int i=4;i<8;i++)
	{
		if ((x&0x01)!=0)
		{
			MCUCR |=(1<<i);
		} 
		else
		{
			MCUCR &=~(1<<i);
		}
		x=x>>1;
	}
}
/************************************************************************/
/* reset by watch dog timer                                                                     */
/************************************************************************/
void init_Watchdogtimer(uint8_t y)
{
	WDTCR|=(1<<WDE);WDTCR &=~(1<<WDTOE);
		for (int i=1;i<5;i++)
		{
			if ((y&0x01)!=0)
			{
				WDTCR |=(1<<i);
			}
			else
			{
				WDTCR &=~(1<<i);
			}
			y=y>>1;
		}
}
/************************************************************************/
/* stop watchdogtimer                                                                    */
/************************************************************************/
void stop_watchdogtimer()
{
	WDTCR|=(1<<WDE);WDTCR |=(1<<WDTOE);
	_delay_ms(4);
	WDTCR&=~(1<<WDE);
	
}