#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

void kmemcpy(uint8_t *source, uint8_t *dest, int nbytes);
void kmemset(uint8_t *dest, uint8_t val, uint32_t len);

uint32_t kmalloc(uint32_t size, int align, uint32_t *phys_addr);

#endif
