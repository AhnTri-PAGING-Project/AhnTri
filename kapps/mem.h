void memanset(){
	char args[];
	int *inpLoc = args[0];
	char *inpDat = args[1];
	char *value = ((char*)stoi(inpLoc));
	printf("One alphabet to store: ");
	inpDat = read_char();
	memcpy(value, inpDat, sizeof(char));
	printf("OK!");
}

void memprintf(){
	char args[];
	int *inpLoc = args[0];
	char *value = ((char*)stoi(inpLoc));
	printf(value);
}
