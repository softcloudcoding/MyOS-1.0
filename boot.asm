; boot.asm (Bootloader, 512 bytes)
[org 0x7C00]
mov si, msg
call print

hang:
    jmp hang

print:
    mov ah, 0x0E
.next:
    lodsb
    or al, al
    jz .done
    int 0x10
    jmp .next
.done:
    ret

msg db 'Booting My OS...', 0

times 510 - ($ - $$) db 0
dw 0xAA55

