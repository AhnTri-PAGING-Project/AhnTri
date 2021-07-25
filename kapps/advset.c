#include "../kernel.h"
#include "../kinc/api.h"

void advset(){
	char cps = KEY_A;
	clscr();
	gotoxy(25, 0);
	printf("AhnTri Advanced settings\n\n");
	printf("1. Change Text color\n");
	printf("2. Change Theme color\n");
	printf("3. Reload GDT\n");
	printf("4. Reload IDT\n");
	printf("5. Send byte to OS\n");
	printf("6. Operating System version\n");
	printf("7. Change keyboard layout\n");
	printf("8. PC CPU ID\n");
	printf("9. Go to kernel main\n");
	printf("a. Change Theme\n");
	printf("b. Change Language\n");
	printf("AhnTroid AI is a part of AhnTri and is protected by the Apache 2.0 open source licence.\n");
	cps = get_input_keycode();
	if(cps == KEY_3){
		clscr();
		init_gdt();
	} else if(cps == KEY_4){
		clscr();
		init_idt();
	} else if(cps == KEY_6){
		clscr();
		osver();
	} else if(cps == KEY_8){
		clscr();
		cputest();
	} else if(cps == KEY_9){
		clscr();
		return;
	}else if(cps == KEY_A){
		printf("In construction");
	}else if(cps == KEY_B){
		printf("What Lanauge?");
		lang();
	} else{
		clscr();
		return;
	}
}
void lang(){
	char capsz = KEY_A;
	printf("Select Text color");
	printf("\nDeafult(1). English\n2. Spanish\n3. Korean\n4. Turk\n");
	suspend(3);
	capsz = get_input_keycode();
	if(capsz == KEY_1){
		clscr();
		qemu_printf_string("Language: set to English.");
		kernmain();
	} else if(capsz == KEY_2){
		clscr();
		qemu_printf_string("Idioma: establezca en español.");
		kernmain_es();
	} else if(capsz == KEY_3){
		clscr();
		qemu_printf_string("언어: 한국어로 설정되었습니다.");
		kernmain_kr();
	} else if(capsz == KEY_4){
		clscr();
		qemu_printf_string("Dil: Türkçe olarak ayarlayın.");
		kernmain_tr();
	} else if(capsz == KEY_5){
		clscr();
	}else{
		printf("No such color. Try again.");
	}
	printf("Color set: Complete.");
}

void inbbyusr(){
	uint16 port;
	port = read_uint();
	inb(port);
}
