#include "ADC.h"

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
/***********************************initialize for free running mode**************************/
void startADC_FreeRunning(uint8_t prescale ,uint8_t Aref)
{
	/*******************set refrence value**********************************/ 
	switch(Aref)
	{
		case 0:
		ADMUX &=~((1<<REFS0)|(1<<REFS1));
		break;
		case 1:
		ADMUX |=(1<<REFS0);ADMUX &=~(1<<REFS1);
		break;
		case 3:
		ADMUX |=((1<<REFS0)|(1<<REFS1));
		break;
	} 
	/***********************set prescale value************************/
	switch(prescale)
	{
		case 0:
		ADCSRA &=~((1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2));
		break;
		case 2:
		ADCSRA &=~((1<<ADPS2)|(1<<ADPS0));
		ADCSRA |=(1<<ADPS1);
		break;
		case 3:
			ADCSRA|=(1<<ADPS0)|(1<<ADPS1);
			ADCSRA &=~(1<<ADPS2);
		break;
		case 4:
          ADCSRA &=~((1<<ADPS1)|(1<<ADPS0));
          ADCSRA |=(1<<ADPS2);
		break;
		case 5:
		ADCSRA|=(1<<ADPS0)|(1<<ADPS2);
		ADCSRA &=~(1<<ADPS1);
		break;
		case 6:
		ADCSRA|=(1<<ADPS2)|(1<<ADPS1);
		ADCSRA &=~(1<<ADPS0);
		break;
		case 7:
		ADCSRA |=((1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2));
		break;
		/*****************************star aden****************/
		ADCSRA |=(1<<ADEN);
	}
}
/***********************************initialize for auto trigger mode mode**************************/
void startADC_Autotrigger(uint8_t source,uint8_t Prescale ,uint8_t ARef)
{	/*******************set refrence value**********************************/
	switch(ARef)
	{
		case 0:
		ADMUX &=~((1<<REFS0)|(1<<REFS1));
		break;
		case 1:
		ADMUX |=(1<<REFS0);ADMUX &=~(1<<REFS1);
		break;
		case 3:
		ADMUX |=((1<<REFS0)|(1<<REFS1));
		break;
	}
	/***********************set prescale value************************/
	switch(Prescale)
	{
		case 0:
		ADCSRA &=~((1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2));
		break;
		case 2:
		ADCSRA &=~((1<<ADPS2)|(1<<ADPS0));
		ADCSRA |=(1<<ADPS1);
		break;
		case 3:
		ADCSRA|=(1<<ADPS0)|(1<<ADPS1);
		ADCSRA &=~(1<<ADPS2);
		break;
		case 4:
		ADCSRA &=~((1<<ADPS1)|(1<<ADPS0));
		ADCSRA |=(1<<ADPS2);
		break;
		case 5:
		ADCSRA|=(1<<ADPS0)|(1<<ADPS2);
		ADCSRA &=~(1<<ADPS1);
		break;
		case 6:
		ADCSRA|=(1<<ADPS2)|(1<<ADPS1);
		ADCSRA &=~(1<<ADPS0);
		break;
		case 7:
		ADCSRA |=((1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2));
		break;
	}
		/****************************select the source ****************************/
		switch(source)
		{
		case 1:
		   SFIOR |=(1<<ADTS0); SFIOR &=~((1<<ADTS1)|(1<<ADPS2));
		break;
		case 2:
		SFIOR |=(1<<ADTS1); SFIOR &=~((1<<ADTS0)|(1<<ADPS2));
		break;
		case 3:
		SFIOR |=((1<<ADTS0)|(1<<ADPS1)); SFIOR &=~(1<<ADTS2);
		break;
		case 4:
		SFIOR |=(1<<ADTS2); SFIOR &=~((1<<ADTS0)|(1<<ADPS1));
		break;
		case 5:
		 SFIOR |=((1<<ADTS0)|(1<<ADPS2)); SFIOR &=~(1<<ADTS1);
		break;
		case 6:
		SFIOR |=((1<<ADTS2)|(1<<ADPS1)); SFIOR &=~(1<<ADTS0);
		break;
		case 7:
		SFIOR |=((1<<ADTS0)|(1<<ADPS1)|(1<<ADTS2)); 
		break;																				
		}
/*****************************star aden****************/
ADCSRA |=(1<<ADEN);
}
/*****************************to select analog channle *******************************/
void select_Analog_ch(uint8_t pin_no)
{
	switch(pin_no)
	{
		case 0:
		ADMUX &=~((1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4));
		break;
		case 1:
		ADMUX |=(1<<MUX0);ADMUX &=~((1<<MUX1)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4));
		break;
		case 2:
		ADMUX |=(1<<MUX0);ADMUX &=~((1<<MUX0)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4));
		break;
		case 3:
        ADMUX |=((1<<MUX0)|(1<<MUX1));ADMUX &=~((1<<MUX2)|(1<<MUX3)|(1<<MUX4));
		break;
		case 4:
		ADMUX |=(1<<MUX2);ADMUX &=~((1<<MUX0)|(1<<MUX1)|(1<<MUX3)|(1<<MUX4));
		break;
		case 5:
		ADMUX |=((1<<MUX0)|(1<<MUX2));ADMUX &=~((1<<MUX1)|(1<<MUX3)|(1<<MUX4));
		break;
		case 6:
		ADMUX |=((1<<MUX1)|(1<<MUX2));ADMUX &=~((1<<MUX0)|(1<<MUX3)|(1<<MUX4));
		break;
		case 7:
		ADMUX |=((1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4));
		break;
	}
}
/****************************************************setting differential analog channel************************/
void select_DifAnalog_ch(uint8_t pin1,uint8_t pin2,uint8_t gainfactor)
{
	
}
/*****************************to select analog channle *******************************/
uint16_t readAnalog()
{	ADCSRA |=(1<<ADSC);
	ADMUX&=~(1<<ADLAR);
	while(ADCSRA&(1<<ADIF)==0);
	uint16_t x=(uint16_t)ADCL;
	uint8_t tmp=ADCH*256;
	
return (x+tmp); 
}
/*************************************** read differential analog channle ********************************/

uint16_t readDifAnalog()
{
	
}
/**************************************selecting and reading******************************/
uint16_t select_read_Analog(uint8_t pp)
{
	select_Analog_ch(pp);
	return readAnalog();	
}
/***************************************select and read differential analog channle ********************************/
uint16_t select_read_DifAnalog(uint8_t pp,uint8_t pp2)
{
	
}