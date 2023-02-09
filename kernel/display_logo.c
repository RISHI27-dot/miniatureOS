#include "display_logo.h"

void display_logo()
{
	clear_screen();
	for(int i = 0; i < 5; i++)
	{
		kprint_at("\n",0,i);
	}
    kprint("Welcome to the MinionOS.\n"); //TODO: Display bigger logo using symbols.
}
