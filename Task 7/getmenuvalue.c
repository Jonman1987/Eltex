#include <stdio.h>

int GetMenuValue() {
	int input_value = 0;

	printf("Calculator App.\n");
	printf("\nMenu:\n");
	fflush(stdout);
	printf("1 - Addition\n");
	printf("2 - Substraction\n");
	printf("3 - Multiplication\n");
	printf("4 - Division\n");
	printf("5 - Exit\n");

	if(scanf("%i", &input_value) != 1) {
		while(fgetc(stdin) != '\n') {
			continue;
		}	
	}

	return input_value;
}