.global _start, irq0_entry, kernel_entry

_start:
    ; kernel initialization
    call kernel_start
    hlt

irq0_entry:
    pushfl
    push eax
    push ecx
    push edx
    ; increment timer, handle nested_count
    call handle_timer_interrupt
    pop edx
    pop ecx
    pop eax
    popfl
    iret

kernel_entry:
    ; called from system calls (yield/exit)
    call scheduler_entry
    ret
