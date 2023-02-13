#include "isr.h"
#include "idt.h"
#include "../drivers/display.h"
#include "../kernel/utils.h"

/* Array of funciton pointer pointint to isr in the interrupt.asm file */
isr_t interrupt_handlers[256];

void install_isr() {
	initialize_idt_gate(0, (uint32_t)isr0);
    initialize_idt_gate(1, (uint32_t)isr1);
    initialize_idt_gate(2, (uint32_t)isr2);
    initialize_idt_gate(3, (uint32_t)isr3);
    initialize_idt_gate(4, (uint32_t)isr4);
    initialize_idt_gate(5, (uint32_t)isr5);
    initialize_idt_gate(6, (uint32_t)isr6);
    initialize_idt_gate(7, (uint32_t)isr7);
    initialize_idt_gate(8, (uint32_t)isr8);
    initialize_idt_gate(9, (uint32_t)isr9);
    initialize_idt_gate(10, (uint32_t)isr10);
    initialize_idt_gate(11, (uint32_t)isr11);
    initialize_idt_gate(12, (uint32_t)isr12);
    initialize_idt_gate(13, (uint32_t)isr13);
    initialize_idt_gate(14, (uint32_t)isr14);
    initialize_idt_gate(15, (uint32_t)isr15);
    initialize_idt_gate(16, (uint32_t)isr16);
    initialize_idt_gate(17, (uint32_t)isr17);
    initialize_idt_gate(18, (uint32_t)isr18);
    initialize_idt_gate(19, (uint32_t)isr19);
    initialize_idt_gate(20, (uint32_t)isr20);
    initialize_idt_gate(21, (uint32_t)isr21);
    initialize_idt_gate(22, (uint32_t)isr22);
    initialize_idt_gate(23, (uint32_t)isr23);
    initialize_idt_gate(24, (uint32_t)isr24);
    initialize_idt_gate(25, (uint32_t)isr25);
    initialize_idt_gate(26, (uint32_t)isr26);
    initialize_idt_gate(27, (uint32_t)isr27);
    initialize_idt_gate(28, (uint32_t)isr28);
    initialize_idt_gate(29, (uint32_t)isr29);
    initialize_idt_gate(30, (uint32_t)isr30);
    initialize_idt_gate(31, (uint32_t)isr31);

    /* Remap the PIC */
    port_byte_out(0x20, 0x11);
    port_byte_out(0xA0, 0x11);
    port_byte_out(0x21, 0x20);
    port_byte_out(0xA1, 0x28);
    port_byte_out(0x21, 0x04);
    port_byte_out(0xA1, 0x02);
    port_byte_out(0x21, 0x01);
    port_byte_out(0xA1, 0x01);
    port_byte_out(0x21, 0x0);
    port_byte_out(0xA1, 0x0);

	/* IRQs */
    initialize_idt_gate(32, (uint32_t)irq0);
    initialize_idt_gate(33, (uint32_t)irq1);
    initialize_idt_gate(34, (uint32_t)irq2);
    initialize_idt_gate(35, (uint32_t)irq3);
    initialize_idt_gate(36, (uint32_t)irq4);
    initialize_idt_gate(37, (uint32_t)irq5);
    initialize_idt_gate(38, (uint32_t)irq6);
    initialize_idt_gate(39, (uint32_t)irq7);
    initialize_idt_gate(40, (uint32_t)irq8);
    initialize_idt_gate(41, (uint32_t)irq9);
    initialize_idt_gate(42, (uint32_t)irq10);
    initialize_idt_gate(43, (uint32_t)irq11);
    initialize_idt_gate(44, (uint32_t)irq12);
    initialize_idt_gate(45, (uint32_t)irq13);
    initialize_idt_gate(46, (uint32_t)irq14);
    initialize_idt_gate(47, (uint32_t)irq15);
	
    initialize_idt();
}

char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void isr_handler(registers_t *r) {
    kprint("received interrupt: ");
    char s[3];
    int_to_ascii(r->int_no, s);
    kprint(s);
    kprint("\n");
	char *str = exception_messages[r->int_no];
    kprint(str);
    kprint("\n");
}

void register_interrupt_handler(uint8_t n, isr_t handler) {
    interrupt_handlers[n] = handler;
}

void irq_handler(registers_t *r) {

	/* Send and EOI after every interupt so that PIC will send next
	 * interupt 
	 */
	if (r->int_no >= 40) 
	  port_byte_out(0xA0, 0x20);
	  port_byte_out(0x20, 0x20);

    /* Handle the interrupt in a more modular way */
    if (interrupt_handlers[r->int_no] != 0) {
        isr_t handler = interrupt_handlers[r->int_no];
        handler(r);
    }
}

