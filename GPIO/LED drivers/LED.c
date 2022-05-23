#include "LED.h"
void led_on(uint8_t x)
{
	out(x,'h');
}
void led_off(uint8_t x0)
{
	out(x0,'l');
}
void led_toggle(uint8_t x1)
{
	toggle(x1);
}
void Blink_led(uint8_t x2,uint32_t y)
{
	out(x2,'h');
	for (int i=0;i<y;i++)
	{
		_delay_ms(1);
	}
	out(x2,'l');
		for (int i=0;i<y;i++)
		{
			_delay_ms(1);
		}
}