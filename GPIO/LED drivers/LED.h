

#ifdef __cplusplus
extern "C" {
	#endif

#include "GPIO.h"
#include <avr/delay.h>


#ifndef LED_H_
#define LED_H_
void led_on(uint8_t x);
void led_off(uint8_t x0);
void led_toggle(uint8_t x1);
void Blink_led(uint8_t x2,uint32_t y);
#endif /* LED_H_ */


	#ifdef __cplusplus
}
#endif