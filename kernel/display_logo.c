#include "display_logo.h"

void display_logo()
{
	clear_screen();
	for(int i = 0; i < 4; i++)
	{
		kprint_at("\n",0,i);
	}
    kprint("                     +------------------------------+\n"); 
    kprint("                     |         miniatureOS.         |\n"); 
    kprint("                     +------------------------------+\n"); 
    //TODO: Display bigger logo using symbols, Or think of some dynamic logo.
}

void print_hr()
{
	kprint("\n");
	for(int j = 0; j < MAX_COLS; j++)
		kprint("-");
	kprint("\n");
}
