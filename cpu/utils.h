#ifndef CPU_UTILS_H
#define CPU_UTILS_H

#include <stdint.h>
// Bitwise masking.
#define low_16(address) (uint16_t)(address & 0xffff)
#define high_16(address) (uint16_t)((address >> 16) & 0xffff)

#endif
