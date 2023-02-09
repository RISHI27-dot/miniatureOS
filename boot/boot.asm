;offset because The BIOS loads this code from the first sector of the hard disk into memory at physical address 0x7c00
[org 0x7c00]

;boot sector for now
times 510 - ($-$$) db 0
dw 0xaa55
