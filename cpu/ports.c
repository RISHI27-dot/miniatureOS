// Read a byte from specific port.
unsigned char port_byte_in(unsigned short port)
{
	unsigned char result;
	__asm__("in %%dx, %%al" : "=a"(result) : "d"(port));
	return result;
}

// Write a byte to specific port
void port_byte_out(unsigned short port, unsigned char data)
{
	__asm__("out %%al, %%dx" : : "a"(data), "d"(port));
}

// Read a word from specific port.
unsigned short port_word_in(unsigned short port)
{
	unsigned short result;
	__asm__("in %%dx, %%ax" : "=a"(result) : "d"(port));
	return result;
}

// Write a word to specific port.
void port_word_out(unsigned short port, unsigned short data)
{
	__asm__("out %%ax, %%dx" : : "a"(data), "d"(port));
}
