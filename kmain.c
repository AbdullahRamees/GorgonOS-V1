    #include "io.h"
    #define FB_GREEN 2
    #define FB_DARK_GREY 8

    /* The I/O ports */
    #define FB_COMMAND_PORT         0x3D4
    #define FB_DATA_PORT            0x3D5
    #define SERIAL_COM1_BASE        0x3F8     

    #define SERIAL_DATA_PORT(base)          (base)
    #define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
    #define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
    #define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
    #define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

    /* The I/O port commands */
    #define FB_HIGH_BYTE_COMMAND    14
    #define FB_LOW_BYTE_COMMAND     15
    #define FB_GREEN	2
    #define FB_DARK_GREY	8
    #define SERIAL_LINE_ENABLE_DLAB         0x80
    char * fb = (char *) 0x000b8000;
    
    void fb_move_cursor(unsigned short pos)
    {
        outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
        outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
        outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
        outb(FB_DATA_PORT,    pos & 0x00FF);
    }
    
    
	//FB write cell 
    void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
	{
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
	}
	
	//serial configur baud rate
    void serial_configure_baud_rate(unsigned short com, unsigned short divisor)
    {
        outb(SERIAL_LINE_COMMAND_PORT(com),
             SERIAL_LINE_ENABLE_DLAB);
        outb(SERIAL_DATA_PORT(com),
             (divisor >> 8) & 0x00FF);
        outb(SERIAL_DATA_PORT(com),
             divisor & 0x00FF);
    }
     void serial_configure_line(unsigned short com)
    {
        
        outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
    }
     int write(char *buf, unsigned int len){
     	fb_write_cell(0, 'A', FB_GREEN, FB_DARK_GREY);
     		

     
     }
    



