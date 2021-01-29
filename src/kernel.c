#include <vgacolor.h>
#include <vgaout.h>

void main(void)
{
	    /* TODO: Add random f-word here */
	terminal_buffer = (unsigned short *)VGA_ADDRESS;
	vga_index = 0;

	clear_screen();
	print_string("ashes", YELLOW);
	newline();    /* calls the nextline function in vgaout.h */
	print_string("to ashes", RED);
	newline();
	print_string("╔═════════════════════════════╗", PINK);
	newline();
	print_string("║		Kernel has finished.	║", PINK);
	newline();
	print_string("║	   Reboot the computer to	║", PINK);
	newline();
	print_string("║		  reinitialize the		║", PINK);
	newline();
	print_string("║				kernel			║", PINK);
	newline();
	print_string("╚═════════════════════════════╝", PINK);
	return;
}

