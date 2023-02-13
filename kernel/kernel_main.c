// Main file for the kernel.
#include "display_logo.h"
#include "utils.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"

void kernel_main()
{
	// display_logo();
	// print_hr();

	//To test interupts
	install_isr();
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");
    __asm__ __volatile__("int $6");
    __asm__ __volatile__("int $35");

}
