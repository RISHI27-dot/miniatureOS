#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <stdio.h>

void kmemcpy(uint8_t *source, uint8_t *dest, int nbytes);
void kmemset(uint8_t *dest, uint8_t val, uint32_t len);
void *kmemchr(uint8_t *source, char ch, int n);
void kmemmove(uint8_t *source, uint8_t *dest, int pos, int nbytes);
int kmemcmp(uint8_t *str1, uint8_t *str2, int nbytes);

uint32_t kmalloc(uint32_t size, int align, uint32_t *phys_addr);

#endif
