int GetMenuValue() {
	int input_value = 0;

	printf("\nMenu:\n");
	fflush(stdout);
	printf("1 - Add abonent\n");
	printf("2 - Delete abonent\n");
	printf("3 - Find abonent by name\n");
	printf("4 - Print all records\n");
	printf("5 - Exit\n");

	if(scanf("%i", &input_value) != 1) {
		while(fgetc(stdin) != '\n') {
			continue;
		}	
	}

	return input_value;
}