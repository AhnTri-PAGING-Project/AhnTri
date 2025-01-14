// include files by #include <neccessary file>
#include "kernel.h"
#include "drivers/kb/char.h"	//So what?
#include "arch/i386/idt.h"
#include "libc/atclib.h"
#include "kapps/clscr.h"
#include "kapps/cpu/ports.h"
#include "kapps/exit.h"
#include "kapps/cpuid.h"
#include "kapps/edxview.h"
#include "kapps/help.h"
#include "kapps/forker.h"
#include "kapps/timermode.h"
#include "kapps/mem.h"
#include "kinc/new.h"
#include "arch/i386/gdt.h"
#include "arch/i386/irq.h"
#include "lang/korean/romanized/kr.h"
#include "lang/turk/romanized/tr.h"
#include "lang/italian/italian.h"
#include "boot/multiboot.h"
#include "mm/pmm.h"
#include "mm/mmap.h"
#include "drivers/sound.h"
#include "strtscrn.h"
#include "fs/fs.h"

//Define Macros
#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))

void display_menu()
{
  printf(" ");
  printf("    Terminal - main menu  ");
  printf("-");
  printf("+");
  printf("x\n");
  printf(" ");
  printf("      AhnTri Terminal        \n");
  framebuffer_putchar(178, 0x8f8f8f);
  printf("  -~=-~=~--~=~--~=~--~=~-=-  \n");
  framebuffer_putchar(178, 0x8f8f8f);
  printf("   Type help for help or o   \n");
  framebuffer_putchar(178, 0x8f8f8f);
  printf("   ther key for each apps.   \n");
  framebuffer_putchar(178, 0x8f8f8f);
  printf("                             \n");
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
  framebuffer_putchar(178, 0x8f8f8f);
}

void kernmain(){
	framebuffer_clscr(0x000000);
	char * choice;
	display_menu();
	while(1){
		printf("\n\n@kern~");
		framebuffer_putchar(30, 0x7fa49d);
		printf(" ");
		choice = read_char();
		if(strcmp(choice, "help")==0){
			help();
		} else if(strcmp(choice, "ccalc")==0 || strcmp(choice, "calc")==0 || strcmp(choice, "accalc")==0){
			ccalc();
			qemu_printf_string("Ccalc App Started");
		} else if(strcmp(choice, "exit")==0){
			exit();
		} else if(strcmp(choice, "osver")==0 || strcmp(choice, "atfetch")==0 || strcmp(choice, "aatfetch")==0){
			osver();
		} else if(strcmp(choice, "clscr")==0 || strcmp(choice, "clear")==0 || strcmp(choice, "aclear")==0 || strcmp(choice, "acls")==0){	//just 4 ppl who are used to dos
			clscr();
		} else if(strcmp(choice, "halt")==0 || strcmp(choice, "shutdown")==0 || strcmp(choice, "ashutdown")==0 || strcmp(choice, "ahalt")==0){
			shutdown();
		} else if(strcmp(choice, "cputest")==0 || strcmp(choice, "cpuid")==0 || strcmp(choice, "acpuid")==0){					//The real name of it was cpuid
			cputest();
		} else if(strcmp(choice, "notes")==0 || strcmp(choice, "anotes")==0){
			notes();
			qemu_printf_string("Notes App Stated");
		} else if(strcmp(choice, "pedx")==0 || strcmp(choice, "apedx")==0){
			pedx();
		} else if(strcmp(choice, "atfork")==0 || strcmp(choice, "aatfork")==0){
			fbomb();
		} else if(strcmp(choice, "memor")==0 || strcmp(choice, "amemor")==0 || strcmp(choice, "memset")==0){
			memanset();
		} else if(strcmp(choice, "mp")==0 || strcmp(choice, "memprintf")==0){
			memprintf();
		} else if(strcmp(choice, "game")==0){
			game();
		} else if(strcmp(choice, "sun")==0){
			art();
		} else if(strcmp(choice, "plant")==0){
			plant();
		} else if(strcmp(choice, "advset")==0){
			advset();
		} else if(strcmp(choice, "devtools")==0){
			devtools();
		} else if(strcmp(choice, "atroid")==0 || strcmp(choice, "ai")==0){
			ahntroid();
		} else if(strcmp(choice, "adic")==0 || strcmp(choice, "dict")==0){
			fdic();
		} else if(strcmp(choice, "cal 2021")==0){
			clscr();
			acal();
		}else if(strcmp(choice, "pit")==0 || strcmp(choice, "timer")==0 || strcmp(choice, "atimer")==0){
			clscr();
			pit(18);
			qemu_printf_string("PIT Timer started");
		}else if(strcmp(choice, "credit")==0 || strcmp(choice, "credits")==0){
			clscr();
			credits();
		}else if(strcmp(choice, "kmap")==0 || strcmp(choice, "kmap kernel")==0){
			clscr();
			print_kernel_map();
		}else if(strcmp(choice, "clibver")==0 || strcmp(choice, "atclibver")==0){
			clscr();
			clibver();
		}else{
			printf("\n");
			printf(choice);
			printf(": command not found");
			qemu_printf_string("Command that was inputted was not found. Sorry.");
		}
	}
}
 
 //Welcome sound
 void beep() {
	play_sound(1000);
	suspend(4);
	play_sound(400);
	suspend(2);
	play_sound(740);
	suspend(7);
	play_sound(800);
	suspend(5);
	nosound();
}

void mkern_main(multiboot_info_t* multiboot)
{
  if (CHECK_FLAG (multiboot->flags, 12)){
    suspend(1);
    qemu_printf_string("Framebuffer flags(12) checked! \\/");
  }
  init_gdt();
  init_idt();
  asm volatile("\tmov $12395, %eax");
  asm volatile("\tint $0");
  irq_install();
  extern uint8_t *_kernel_end;								//Defined in Linker.ld
  uint32_t sizeofpmminit = multiboot->mem_upper + 1024;
  pmm_init((uint32_t) &_kernel_end, sizeofpmminit);
  pmm_init_availreg(multiboot->mmap_addr, multiboot->mmap_addr+multiboot->mmap_length);
  pmm_kernel_deinit();
  qemu_printf_string("Everything is initialized. System is starting...");
  init_tty(multiboot, 0x7fa49d, 0x000000);
  suspend(4);
  uint32_t initrd_location = *((u32int*)multiboot->mods_addr);
  uint32_t initrd_end = *(u32int*)(multiboot->mods_addr+4);
  fs_root = init_initrd(initrd_location);
  int i = 0;
    struct dirent *node = 0;
    while ( (node = readdir_fs(fs_root, i)) != 0)
    {
        printf("Found file ");
        printf(node->name);
        fs_node_t *fsnode = finddir_fs(fs_root, node->name);

        if ((fsnode->flags&0x7) == FS_DIRECTORY)
        {
            printf("\n(directory)\n");
        }
        else
        {
            printf("\n contents: \"");
            char buf[256];
            u32int sz = read_fs(fsnode, 0, 256, buf);
            int j;
            for (j = 0; j < sz; j++)
                print_char(buf[j]);
            
            printf("\"\n");
        }
        i++;
    }

    return 0;
}
