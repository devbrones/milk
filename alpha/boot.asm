bits 32

section .multiboot               ;according to multiboot spec
        dd 0x1BADB002            ;set magic number for
                                 ;bootloader
        dd 0x0                   ;set flags
        dd - (0x1BADB002 + 0x0)  ;set checksum

section .text
global start
global kbin	
global kbsend
global load_idt
global keyboard_handler
extern keyboard_handler_main
extern main                      ;defined in the C file

kbin:
		mov edx, [esp + 4]
		in al, dx
		ret

kbsend:
		mov edx, [esp + 4]
		mov al, [esp + 4 + 4]
		out dx, al
		ret

load_idt:
		mov edx, [esp + 4]
		lidt [edx]
		sti
		ret
keyboard_handler:
		call keyboard_handler_main
		iretd

start:
        cli                      ;block interrupts
        mov esp, stack_space     ;set stack pointer
        call main
        hlt                      ;halt the CPU

section .bss
resb 8192                        ;8KB for stack
stack_space:
