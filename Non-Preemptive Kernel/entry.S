.global kernel_entry
kernel_entry:
    # Save registers
    pushl %eax
    pushl %ebx
    pushl %ecx
    pushfl

    # Call C function for yield or exit
    call do_yield

    # Restore registers
    popfl
    popl %ecx
    popl %ebx
    popl %eax
    ret
