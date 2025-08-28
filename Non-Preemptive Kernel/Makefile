CC = gcc
AS = as
LD = ld

all: kernel.img

kernel.o: kernel.c common.h
    $(CC) -m32 -c kernel.c -o kernel.o

scheduler.o: scheduler.c common.h
    $(CC) -m32 -c scheduler.c -o scheduler.o

tasks.o: tasks.c common.h
    $(CC) -m32 -c tasks.c -o tasks.o

lock.o: lock.c common.h
    $(CC) -m32 -c lock.c -o lock.o

util.o: util.c common.h
    $(CC) -m32 -c util.c -o util.o

entry.o: entry.S
    $(AS) --32 entry.S -o entry.o

syslib.o: syslib.S
    $(AS) --32 syslib.S -o syslib.o

kernel.img: kernel.o scheduler.o tasks.o lock.o util.o entry.o syslib.o
    $(LD) -m elf_i386 -Ttext 0x1000 -o kernel.img kernel.o scheduler.o tasks.o lock.o util.o entry.o syslib.o

clean:
    rm -f *.o kernel.img
