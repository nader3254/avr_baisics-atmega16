#include <avr/io.h>

#ifndef POWER_RESET_CONFIG_H_
#define POWER_RESET_CONFIG_H_


#define IDLE 0
#define ADC_NOISE_REDUCATION 1
#define POWER_DOWN 2
#define POWER_SAVE 3
#define STANDBY 6
#define sixteen_millesecond 0
#define thirtytwo_millesecond 1
#define sixtyfour_millesecond 2
#define opointone_second 3
#define opointtwo_second 4
#define opointfive_second 5
#define one_second 6
#define two_second 7

#define EXTENDED_STANDBY 7
void power_mode(uint8_t x);
void init_Watchdogtimer(uint8_t y);
void stop_watchdogtimer();

#endif /* POWER_RESET_CONFIG_H_ */