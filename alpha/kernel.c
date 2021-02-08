#include <kernelentries.h>
#include <vgaout.h>
#include <idt.h>
#include <kbh.h>

void main(void)
{
	    /* TODO: Add random f-word here */
	terminal_buffer = (unsigned short *)VGA_ADDRESS;
	vga_index = 0;

	clear_screen();
	print_string("ashes", YELLOW);
	newline();    /* calls the nextline function in vgaout.h */
	print_string("to ashes", RED);
	print_string("\r\r\r\r\r\r", WHITE_COLOR);
	newline();
	print_string("newline", GREEN);
	vga_index = 320;
	print_string("test", PINK);
	vga_index = 400;
	return;
	/*this is where we want to initialise the keyboard input, we would do this by sending commands to the controller that are defined in the boot.asm file, we can use strings such as kbin() and kbsend() and kbinit()*/
	
}

