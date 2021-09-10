#include "io.h"
#include "serial.h"
#include "framebuffer.h"
#include "keyboard.h"
#include "memory_segments.h"
#include "interrupts.h"
#include "multiboot.h"
#include "paging.h"

char message[]= "Gorgon OS";



int kmain(multiboot_info_t *mbinfo)
{
	/* Test appel module 
	module_t* modules = (module_t*) mbinfo->mods_addr;       
	unsigned int address_of_module = modules->mod_start;     

	typedef void (*call_module_t)(void);
	call_module_t start_program = (call_module_t) address_of_module;
    	start_program(); */

	/*fb_clear();*/
	fb_move_cursor(6*80);
	fb_write_str(message,sizeof(message));
	/*fb_write_str("hello\n",5); TODO */
	serial_write(message,sizeof(message));
	segments_install_gdt();
	interrupts_install_idt();
	
	init();
    	
  	multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
  	multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr; 
  	unsigned int address_of_module = modules->mod_start;
  	if((mbinfo->mods_count) == 1){
  		char message[] = "ONE module loaded successfully!";
  		serial_write(0x3F8,message,sizeof(message));
  		
  		typedef void (*call_module_t)(void);
        	/* ... */
        	call_module_t start_program = (call_module_t) address_of_module;
        	start_program();
        	/* we'll never get here, unless the module code returns */

  	}else{
  		char message[] = "Error: More than ONE module loaded";
  		serial_write(0x3F8,message,sizeof(message));
  	}
		
	init_paging();
	/* test page fault 	
	unsigned int *ptr = (unsigned int*)0xA0000000;
   	unsigned int do_page_fault = *ptr;*/
	

	return 0;

}
