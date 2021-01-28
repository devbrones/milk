CC=gcc
NASMARGS = elf32
GCCARGS = -m32
LDARGS = -m elf_i386
ISONAME = kilm.iso
DEPS = kernel.c boot.asm linker.ld

boot:
	nasm -f  $(NASMARGS) boot.asm -o boot.o

kernel:
	gcc $(GCCARGS) -c kernel.c -o kernel.o

linker:
	ld $(LDARGS) -T linker.ld -o kernel boot.o kernel.o

mkiso:
	mkdir -p iso/boot/grub
	cp kernel iso/boot/
	cp grub.cfg iso/boot/grub/
	grub-mkrescue -o $(ISONAME) iso/
	echo "iso is", $(ISONAME)

.PHONY: clean
clean:
	rm -rf *.o kernel
