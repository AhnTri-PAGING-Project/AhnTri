#include "../kio/types.h"
extern void print_char(char ch);
extern void printf(char *str);
extern void init_vga(uint8 fg_color, uint8 bg_color);
extern void printf(char *str);
extern void os_print_color(char *str, uint8 fore_color, uint8 back_color);
extern int read_int();
extern void suspend(uint32 timer_count);
extern int get_input_keycode();
extern uint8 inb(uint16 port);
extern int read_uint();
