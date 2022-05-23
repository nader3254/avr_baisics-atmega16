 #include <avr/io.h>
#include "BUTTON.h"

int main(void)
{
	set_button(A3);
    /* Replace with your application code */
    while (1) 
    {
		if (read_button(A3))
		{
			PORTD=0x06;
		} 
		else
		{
			PORTD=0x0;
		}
    }
}

