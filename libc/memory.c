#include "memory.h"

void kmemcpy(uint8_t *source, uint8_t *dest, int nbytes)
{
	int i;
	for (i = 0; i < nbytes; i++) {
		*(dest + i) = *(source + i);
	}
}

void kmemset(uint8_t *dest, uint8_t val, uint32_t len)
{
	uint8_t *temp = (uint8_t *)dest;
	for (; len != 0; len--)
		*temp++ = val;
}

uint32_t free_mem_addr = 0x10000;
uint32_t kmalloc(uint32_t size, int align, uint32_t *phys_addr)
{
	/* Pages are aligned to 4K, or 0x1000 */
	if (align == 1 && (free_mem_addr & 0xFFFFF000)) {
		free_mem_addr &= 0xFFFFF000;
		free_mem_addr += 0x1000;
	}
	/* Save also the physical address */
	if (phys_addr)
		*phys_addr = free_mem_addr;

	uint32_t ret = free_mem_addr;
	free_mem_addr += size;
	return ret;
}