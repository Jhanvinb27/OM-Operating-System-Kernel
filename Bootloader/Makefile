AS = as --32
LD = ld -m elf_i386
CC = gcc -m32
OBJS = bootblock.o kernel.o

all: os-image

bootblock.o: bootblock.s
	$(AS) bootblock.s -o bootblock.o

kernel.o: kernel.s
	$(AS) kernel.s -o kernel.o

os-image: bootblock.o kernel.o createimage
	./createimage os-image.img bootblock kernel

createimage: createimage.c
	$(CC) createimage.c -o createimage

clean:
	rm -f *.o createimage os-image.img
