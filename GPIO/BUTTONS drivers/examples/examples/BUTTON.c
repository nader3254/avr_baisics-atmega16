#include "BUTTON.h"

uint8_t read_button(uint8_t a)
{
   return	read(a);
}
void set_button(uint8_t x)
{
	inp(x);
}