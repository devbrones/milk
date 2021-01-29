CC=gcc
NASMARGS = elf32
GCCARGS = -m32
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
	gcc $(GCCARGS) -c $(PATHTO)kernel.c -o $(PRELN)kernel.o

linker:
	ld $(LDARGS) -T linker.ld -o $(BIN)kernel $(PRELN)boot.o $(PRELN)kernel.o

mkiso:
	mkdir -p iso/boot/grub
	cp $(BIN)kernel iso/boot/
	cp $(PATHTO)grub.cfg iso/boot/grub/
	grub-mkrescue -o $(ISONAME) iso/
	echo "iso is", $(ISONAME)

.PHONY: clean
clean:
	rm -rf *.o kernel
