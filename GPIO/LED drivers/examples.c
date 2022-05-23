
#include "LED.h"
#define F_CPU 8000000UL
#define led1 A0
#define led2 A1
#define led3 A2
#define led4 A3
#define led5 A4
#define led6 A5
#define led7 A6
#define led8 A7
int main(void)
{
   
    while (1) 
    {	led_on(led1);led_on(led2);led_on(led3);led_on(led4);
	    led_on(led5);led_on(led6);led_on(led7);led_on(led8);
	    _delay_ms(2000);
	    led_off(led1);led_off(led2);led_off(led3);led_off(led4);
	    led_off(led5);led_off(led6);led_off(led7);led_off(led8);
	    _delay_ms(2000);
	    led_toggle(led1);led_toggle(led2);led_toggle(led3);led_toggle(led4);
	    led_toggle(led5);led_toggle(led6);led_toggle(led7);led_toggle(led8);
	    _delay_ms(2000);
	    led_toggle(led1);led_toggle(led2);led_toggle(led3);led_toggle(led4);
	    led_toggle(led5);led_toggle(led6);led_toggle(led7);led_toggle(led8);
	    _delay_ms(2000);
	
		
		Blink_led(led8,500);Blink_led(led1,500);Blink_led(led4,500);Blink_led(led6,500);
		
		
		
    }
}

