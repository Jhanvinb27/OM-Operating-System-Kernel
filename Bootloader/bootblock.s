; bootblock.s - Bootloader for COS 318 Project 1
; Assembled with: as --32 bootblock.s -o bootblock.o

[ORG 0x7C00]          ; BIOS loads bootblock here

start:
    cli                 ; Disable interrupts
    xor ax, ax
    mov ds, ax
    mov es, ax

    ; Save boot drive number
    mov [boot_drive], dl

    ; Setup stack
    mov ax, 0x9000
    mov ss, ax
    mov sp, 0xFFFF

    sti                 ; Enable interrupts

    ; Print test string
    mov si, test_string
    call print_string

    ; Halt CPU (for now)
hang:
    hlt
    jmp hang

; -------------------
; Print functions
; -------------------
print_char:
    mov ah, 0x0E       ; BIOS teletype function
    int 0x10
    ret

print_string:
.next_char:
    lodsb
    cmp al, 0
    je .done
    call print_char
    jmp .next_char
.done:
    ret

; -------------------
; Data
; -------------------
boot_drive: db 0
test_string: db 'Bootloader loaded!',0

times 510-($-$$) db 0  ; Pad to 510 bytes
dw 0xAA55              ; Boot signature
