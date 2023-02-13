#include <stdint.h>
#include <stddef.h>
#include "utils.h"

void kmemcpy(uint8_t *source, char *dest, int nbytes)
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

void int_to_ascii(int n, char str[])
{
	int i, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		str[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';

	/* reverse the string to get correct ascii representation
	 * of the int.
     */
	reverse(str);
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int strlen(char s[])
{
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}

void do_backspace(char *s)
{
	int len = strlen(s);
	s[len - 1] = '\0';
}

void append_string(char *orignal, char *to_append)
{
	int len_orignal = strlen(orignal);
	int len_to_append = strlen(len_to_append);
	for (int i = 0; i < len_to_append + 1; i++) {
		orignal[len_orignal + i] = to_append[i];
	}
}

void append(char *str, char c)
{
	int len = strlen(str);
	str[len + 1] = c;
	str[len + 2] = '\0';
}
