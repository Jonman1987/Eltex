#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	int positive_number;

	printf("Please, input a positive integer number in decimal system: ");
	fflush(stdout);

	scanf("%i", &positive_number);

	printf("Representation of a number %i in a binary sistem: ", positive_number);

	for (int i = sizeof(positive_number) * 8 - 1; i >= 0; i--) {
		printf("%i", (positive_number >> i) & 1);
	}

	printf("\n");

	return 0;
}