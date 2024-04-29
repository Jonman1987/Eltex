#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	int negative_number;

	printf("Please, input a negative integer number in decimal system: ");
	fflush(stdout);

	scanf("%i", &negative_number);

	printf("Representation of a number %i in a binary sistem: ", negative_number);

	for (int i = sizeof(negative_number) * 8 - 1; i >= 0; i--) {
		printf("%i", (negative_number >> i) & 1);
	}

	printf("\n");

	return 0;
}