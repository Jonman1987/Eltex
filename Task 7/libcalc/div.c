#include <stdio.h>
#include <stdlib.h>

void Division(int* first_number, int* second_number) {
	double result = 0;

	system("clear");

	if(*second_number == 0){
		printf("Error. Division by zero!");
		printf("\n");
	} else{
		printf("Result: %.2f", (float)(*first_number) / *second_number);
		printf("\n");
	}
}