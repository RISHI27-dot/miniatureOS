// Main file for the kernel.
#include "display_logo.h"
#include "utils.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"
#include "../drivers/keyboard.h"

void kernel_main()
{
	// display_logo();
	// print_hr();

	//To test interupts
	install_isr();
	__asm__ __volatile__("int $2");
	__asm__ __volatile__("int $3");

	__asm__ __volatile__("sti");
	// init_timer(50);
	init_keyboard();
}

void user_input(char *input)
{
	if (strcmp(input, "END") == 0) {
		kprint("Stopping the CPU. Bye!\n");
		asm volatile("hlt");
	}
	kprint("You said: ");
	kprint(input);
	kprint("\n> ");
}
