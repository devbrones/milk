void kb_init(void)
{
	/* 0xFD is 11111101 - enables only irq1 which we use for kb input */
	write_port(0x21 , 0xFD);
}

void keyboard_handler_main(void) 
