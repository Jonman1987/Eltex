#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	int positive_number;
	int number_units_count = 0;


	printf("Please, input a positive integer number in decimal system: ");
	fflush(stdout);

	scanf("%i", &positive_number);

	printf("Representation of a number %i in a binary sistem: ", positive_number);

	for (int i = sizeof(positive_number) * 8 - 1; i >= 0; i--)
	{
		if((positive_number >> i) & 1 == 1){
			number_units_count++;
		}

		printf("%i", (positive_number >> i) & 1);
	}

	printf("\n");
	printf("Count of number units is %i", number_units_count);
	printf("\n");

	return 0;
}