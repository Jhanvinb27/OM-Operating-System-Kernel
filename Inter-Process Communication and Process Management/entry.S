.section .text
.global irq0_entry
.global irq1_entry
.global system_call_entry

irq0_entry:
    # Timer interrupt handler (leave as is for now)
    iret

irq1_entry:
    # Keyboard interrupt handler
    iret

system_call_entry:
    # System call handler
    iret
