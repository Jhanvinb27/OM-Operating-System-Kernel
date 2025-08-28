.global yield
yield:
    movl $0, %eax  # syscall number for yield
    call *ENTRY_POINT
    ret

.global exit
exit:
    movl $1, %eax  # syscall number for exit
    call *ENTRY_POINT
    ret
