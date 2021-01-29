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
	print_string("\r\r\r\r\r\r", WHITE_COLOR);
	newline();
	print_string("newline", GREEN);
	print_string("╔═════════════════════════════╗", RED);
	newline();
	print_string("║		Kernel has finished.	║", RED);
	newline();
	print_string("║	   Reboot the computer to	║", RED);
	newline();
	print_string("║		  reinitialize the		║", RED);
	newline();
	print_string("║				kernel			║", RED);
	newline();
	print_string("╚═════════════════════════════╝", RED);
	return;
}

