void antroid_hmenu(){
	printf("\nArtificial Intellegence by AhnTri: Type [6390] for help. Do not input nothing, or it would crash.");
}

void ahntroid(){
	init_vga(BRIGHT_BLUE, BLACK);
	char * input;
	antroid_hmenu();
	while(1){
		printf("\n\nUser_Master| ");
		input = read_char();
		if(strcmp(input, "hello")==0 || strcmp(input, "hola")==0 || strcmp(input, "hi")==0 || strcmp(input, "hi man")==0 || strcmp(input, "dude")==0){
			printf("Hello, User Master. This AI is well-trained by arrays of words or numbers");
			printf("\nbut have only one output. Whatever, have a good day!");
			free(input);
		}else if(strcmp(input, "bye")==0 || strcmp(input, "good bye")==0 || strcmp(input, "bye")==0){
			printf("Bye-Bye, Good-Bye!!");
			init_vga(CYAN, BLACK);
			kernmain();
		}else if(strcmp(input, "help")==0){
			printf("Help: exit() to exit");
			free(input);
		}else if(strcmp(input, "wow")==0 || strcmp(input, "whow")==0 || strcmp(input, "omg")==0 || strcmp(input, "lol")==0){
			printf("Why, is AhnTriOS too good? If is, give a *heart in Github!");
			free(input);
		}else if(strcmp(input, "happi")==0 || strcmp(input, "happy")==0 || strcmp(input, "good")==0 || strcmp(input, "great")==0 || strcmp(input, "thanks")==0){
			printf("I am happy to hear that you are happy!");
			free(input);
		}else if(strcmp(input, "fu")==0 || strcmp(input, "fuck")==0 || strcmp(input, "fuck u")==0 || strcmp(input, "fuck you")==0 || strcmp(input, "crap")==0 || strcmp(input, "shit")==0 || strcmp(input, "jesus")==0){
			printf("Don't say those words. If you do, fuck you :(");
			free(input);
		}else if(strcmp(input, "who are u")==0 || strcmp(input, "what is your gender")==0 || strcmp(input, "whoareu")==0 || strcmp(input, "uname")==0){
			printf("I am AhnTroid. I am an man bot. I am Artificial Intellegence.");
			free(input);
		}else{
			printf("Word not trained or not exist in code.");
			
		}
	}
}