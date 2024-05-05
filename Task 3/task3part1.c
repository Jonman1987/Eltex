#include <stdio.h>

int main(int argc, char const *argv[])
{
	int changeable_number;
	int change_number;

	char *pointer_one;
	char *pointer_two;

	printf("Please, input a positive integer number in decimal system, which will be changed: ");
	fflush(stdout);

	scanf("%i", &changeable_number);

	pointer_one = (char*) &changeable_number;

	printf("First number before change: ");

	for (int i = sizeof(changeable_number) * 8 - 1; i >= 0; i--) { // I use bite operation only for showing bite representation of number
		printf("%i", (changeable_number >> i) & 1);

		if(i % 8 == 0 && i != 0) {
			printf(" ");
		}
	}

	printf("\n\nPlease, input a positive integer number in decimal system, which change: ");


	scanf("%i", &change_number);

	pointer_two = (char*) &change_number;

	printf("Second number before change: ");

	for (int i = sizeof(change_number) * 8 - 1; i >= 0; i--) {
		printf("%i", (change_number >> i) & 1);

		if(i % 8 == 0 && i != 0) {
			printf(" ");
		}
	}

	pointer_one = pointer_one + 2;

	*pointer_one = *pointer_two;

	printf("\n\nResult: ");

	for (int i = sizeof(changeable_number) * 8 - 1; i >= 0; i--) {
		printf("%i", (changeable_number >> i) & 1);

		if(i % 8 == 0 && i != 0) {
			printf(" ");
		}
	}

	return 0;
}