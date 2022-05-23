#include <avr/io.h>
#include "GPIO.h"  //including our library
#include <avr/delay.h>
#define F_CPU 8000000UL
#define led1 A5
#define button B5
#define button2 C5
#define led2 D5
#define led3 D0
#define led4 D3
int main(void)
{
	inp(button);//set pin B5 as input
	inp_up(button2);//set pin C5 as input pull_up
    out(led1,'l');//set initial state for led 1 at A5 as low
	out(led2,'l');//set initial state for led 2 at D5 as low
    while (1) 
    {out(led1,'h');_delay_ms(500);//set led 1 at A5 as high
	 out(led1,'l');_delay_ms(500);//set led 1 at A5 as low
     toggle(led2);//toggle led 2 
	 if (read(button))
	 {
		 out(led3,'h');
	 } 
	 else
	 {
		 out(led3,'l');
	 }  //according to the reading value of button will set high or low to led 3
     	 if (read(button2))
     	 {
	     	 out(led4,'h');
     	 }
     	 else
     	 {
	     	 out(led4,'l');
     	 }  //according to the reading value of button2 will set high or low to led 4
     	  
		  
    }
}

