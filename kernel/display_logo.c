#include "display_logo.h"

void display_logo()
{
	clear_screen();
	for(int i = 0; i < 7; i++)
	{
		kprint_at("\n",0,i);
	}
    kprint("                     +------------------------------+\n"); 
    kprint("                     |         miniatureOS.         |\n"); 
    kprint("                     +------------------------------+\n"); 
    //TODO: Display bigger logo using symbols, Or think of some dynamic logo.
}
