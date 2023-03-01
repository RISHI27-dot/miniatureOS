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

void kmemmove(uint8_t *source, uint8_t *dest, int pos, int nbytes)
{
	int i;
	for (i = pos; i < pos+ nbytes; i++) {
		*(dest + i) = *(source + i);
	}
}

int kmemcmp(uint8_t *str1, uint8_t *str2, int nbytes)
{
	int i;int count = 0;
	for (i = 0; i < nbytes; i++) {
		if (*(str1 + i) == *(str2 + i))
		{
			count++;
		}
		if (*(str1 + i) < *(str2 + i))
		{
			return -1;
		}
		if (*(str1 + i) > *(str2 + i))
		{
			return 	1;
		}
	}
	if (count == nbytes)
	{
		return 0;
	}
}