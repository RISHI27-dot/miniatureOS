#ifndef KERNEL_UTILS_H
#define KERNEL_UTILS_H

#include <stdint.h>
#include <stddef.h>

void memory_set(uint8_t *dest, uint8_t val, uint32_t len);
void kmemcpy(uint8_t *source, char *dest, int nbytes);
void int_to_ascii(int n, char str[]); 
void reverse(char s[]);
int strlen(char s[]);

#endif

