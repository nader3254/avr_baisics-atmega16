#include <avr/io.h>


#ifndef ADC_H_
#define ADC_H_
/******************for setting analog pin******************/
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
/******************for setting aref******************/
#define AREF 0
#define AREF_capacitor 1
#define internalAREF 3
/******************for setting prescale division factor******************/
#define Df2 0
#define Df4 2
#define Df8 3
#define Df16 4
#define Df32 5
#define Df64 6
#define Df128 7
/******************for setting auto trigger source******************/
#define Analog_compare 1
#define External_intrrupt 2
#define Timer0_compare_match 3
#define Timer0_overflow 4
#define Timer1_compare_matchB 5
#define Timer1_overflow 6
#define Timer1_capture_event 7
/***********************our functions ****************************/
void startADC_FreeRunning(uint8_t prescale ,uint8_t Aref);
void startADC_Autotrigger(uint8_t source,uint8_t Prescale ,uint8_t ARef);
void select_Analog_ch(uint8_t pin_no);
void select_DifAnalog_ch(uint8_t pin1,uint8_t pin2,uint8_t gainfactor);
uint16_t readAnalog(void);
uint16_t readDifAnalog(void);
uint16_t select_read_Analog(uint8_t pp);
uint16_t select_read_DifAnalog(uint8_t pp,uint8_t pp2);
#endif /* ADC_H_ */