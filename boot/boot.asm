;offset because The BIOS loads this code from the first sector of the hard disk into memory at physical address 0x7c00
[org 0x7c00]

%include "boot/disk.asm"

KERNEL_OFFSET equ 0x1000 ; The kernel will be loaded here
call load_kernel

load_kernel:
	mov bx, KERNEL_OFFSET
    mov dh, 16 ; number of sectors to load. TODO: find a better approach.
    mov dl, [BOOT_DRIVE]
    call load_from_disk ; load from the disk
    ret

BOOT_DRIVE db 0 ; drive number
;boot sector for now
times 510 - ($-$$) db 0
dw 0xaa55
