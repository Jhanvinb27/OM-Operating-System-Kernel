CC=gcc
AS=nasm
CFLAGS=-m32 -Wall -O0
LDFLAGS=-m32

all: kernel.img

kernel.img: bootblock kernel
    cat bootblock kernel > kernel.img

kernel: kernel.o scheduler.o interrupt.o syslib.o sync.o queue.o
    $(CC) $(LDFLAGS) -o kernel kernel.o scheduler.o interrupt.o syslib.o sync.o queue.o

%.o: %.c
    $(CC) $(CFLAGS) -c $<

%.o: %.S
    $(AS) -f elf32 $< -o $@

clean:
    rm -f *.o kernel kernel.img
