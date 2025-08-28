; kernel.s - Minimal kernel for COS 318 Project 1
[ORG 0x1000]           ; Load address

start:
    mov si, kernel_msg
    call print_string
    hlt
    jmp $

print_char:
    mov ah, 0x0E
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

kernel_msg: db 'Kernel > Running a trivial test... Test passed!',0
