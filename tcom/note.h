void notetake()
{
  char ch = 0;
  char inp = 0;
  do{
    inp = get_input_keycode();
    if(keycode == KEY_ENTER){
    	printf("\n");
     } else if(keycode == KEY_ESC){
     	clscr();
     	kernmain();
    }else{
      ch = get_ascii_char(keycode);
      print_char(ch);
    }
  }while(ch > 0);
}

void display_help()
{
  gotoxy(25, 0);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color(" /-----------------------/ |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color(" ------------------------| |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("|    AhnTri NoteTaker    | |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("|-~=-~=~--v1.3-~=~--~=~--| |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("| Take notes and do not  | |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("| shut down the PC then. | |", WHITE, BRIGHT_BLUE);
  os_print_color("\n                           ", BLACK, BLACK);
  os_print_color("-------------------------|/ ", WHITE, BRIGHT_BLUE);
}

void notes(){
	display_help();
	printf("\nStarting Notetaker");
	suspend(100);
	clscr();
	printf("\n");
	notetake();
}
