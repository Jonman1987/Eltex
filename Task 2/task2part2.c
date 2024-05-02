#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array_length;

	printf("Please, input a positive integer number equal array size: ");
	fflush(stdout);

	scanf("%i", &array_length);

	int array[array_length];

	printf("Please, input %i numbers seporated with space: ", array_length);
	
	for (int i = 0; i < array_length; ++i) {
		scanf("%i", &array[i]);
	}

	printf("Current array:\n");

	for (int i = 0; i < array_length; ++i) {
		printf("%i ", array[i]);
	}

	for (int i = 0; i < array_length / 2; ++i) {
		int tmp = array[i];

		array[i] = array[array_length - 1 - i];
		array[array_length - 1 - i] = tmp;
	}

	printf("\nResult of reverse:\n");

	for (int i = 0; i < array_length; ++i) {
		printf("%i ", array[i]);
	}

	return 0;
}