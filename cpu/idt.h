#ifndef IDT_H
#define IDT_H

#define KERNEL_CS 0x08

#include "utils.h"

/* Note: here the order of the field matters as the standards.
   defining fields in order other than this will create problems
   when the cpu tries to read idt */
typedef struct {
    uint16_t low_offset; /* Lower 16 bits of handler function address */
    uint16_t sel; /* Kernel segment selector */
    uint8_t always0;
    /* First byte
     * Bit 7: "Interrupt is present"
     * Bits 6-5: Privilege level of caller (0=kernel..3=user)
     * Bit 4: Set to 0 for interrupt gates
     * Bits 3-0: bits 1110 = decimal 14 = "32 bit interrupt gate" */
    uint8_t flags; 
    uint16_t high_offset; /* Higher 16 bits of handler function address */
} __attribute__((packed)) idt_gate_t ;


typedef struct {
  uint16_t limit;
  uint32_t base;
}__attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256

idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void initialize_idt_gate();
void initialize_idt();

#endif
