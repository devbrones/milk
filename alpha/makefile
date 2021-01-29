CC=gcc
NASMARGS = elf32
GCCARGS = -I /lib32/ -I src/ -m32 -std=c89
LDARGS = -m elf_i386 
ISONAME = kilm.iso
DEPS = kernel.c boot.asm linker.ld
PATHTO = src/
PRELN = pld/
BIN = bin/

.PHONY: all
all: boot kernel linker mkiso
	@echo Make has finished 

boot:
	nasm -f  $(NASMARGS) $(PATHTO)boot.asm -o $(PRELN)boot.o

kernel:
	gcc $(GCCARGS) -c $(PATHTO)kernel.c -o $(PRELN)kernel.o -nostartfiles

linker:
	ld $(LDARGS) -T $(PATHTO)linker.ld -o $(BIN)kernel $(PRELN)boot.o $(PRELN)kernel.o -Lc -L/lib32/ld-linux.so.2  

mkiso:
	mkdir -p iso/boot/grub
	cp $(BIN)kernel iso/boot/
	cp $(PATHTO)grub.cfg iso/boot/grub/
	grub-mkrescue -o $(ISONAME) iso/
	echo "iso is", $(ISONAME)

.PHONY: clean
clean:
	rm -rf *.o kernel
