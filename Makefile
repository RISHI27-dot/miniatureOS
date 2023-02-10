C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)
# This replaces .c files to .o in C_SOURCES.
OBJ = ${C_SOURCES:.c=.o}

# Set this so that the corsscompiler is discovered.
CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb
# -g: Use debugging symbols in gcc
CFLAGS = -g

# First rule is run by default
miniatureOS-image.bin: boot/boot.bin kernel.bin
	cat $^ > miniatureOS-image.bin

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: boot/kernel_entry_point.o ${OBJ}
	i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

# Used for debugging purposes
kernel.elf: boot/kernel_entry_point.o ${OBJ}
	i386-elf-ld -o $@ -Ttext 0x1000 $^ 

run: miniatureOS-image.bin
	qemu-system-i386 -fda miniatureOS-image.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: miniatureOS-image.bin kernel.elf
	qemu-system-i386 -s -fda miniatureOS-image.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o miniatureOS-image.bin *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o

