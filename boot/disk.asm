; load 'dh' sectors from drive 'dl' into ES:BX
load_from_disk:
    pusha
    push dx

    mov ah, 0x02 ; setting 0x02 in ah implies 'read'
    mov al, dh   ; number of sectors to read
    mov cl, 0x02 ; 0x01 is our boot sector, 0x02 is the first 'available' sector
    mov ch, 0x00 ; cylinder
    mov dh, 0x00 ; head number

    int 0x13      ; BIOS interrupt to read.
    jc disk_error ; if error (stored in the carry bit) loop. TODO: Add error checking.

    pop dx
    cmp al, dh    ; BIOS also sets 'al' to the # of sectors read. Compare it.
    popa
    ret


disk_error:
    jmp disk_loop

disk_loop:
    jmp $
