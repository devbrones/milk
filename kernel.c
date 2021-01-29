#include <kernel.h>

unsigned short *terminal_buffer;
unsigned int vga_index;

void clear_screen(void)
{
	    int index = 0;
	        /* there are 25 lines each of 80 columns;
		 *        each element takes 2 bytes */
	    while (index < 80 * 25 * 2) {
			terminal_buffer[index] = ' ';
			index += 2;
		}
}

void print_string(char *str, unsigned char color)
{
	int index = 0;
	while (str[index]) {
		terminal_buffer[vga_index] = (unsigned short)str[index]|(unsigned short)color << 8;
		index++;
		vga_index++;
							        }
}
void newline(void)
{
	vga_index = vga_index + 80;
}	
void main(void)
{
	    /* TODO: Add random f-word here */
	    terminal_buffer = (unsigned short *)VGA_ADDRESS;
	        vga_index = 0;

		    clear_screen();
		        print_string("ashes", YELLOW);
			    newline();    /* next line */
			        print_string("to ashes", RED);
				    return;
}

