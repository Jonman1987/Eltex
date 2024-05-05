#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array_size = 10;
	int array[array_size];
	int *p = &array[0];

	for (int i = 0, array_value = 1; i < array_size; ++i, ++array_value) {
		array[i] = array_value;
	}

	printf("Result:\n");

	for (int i = 0; i < array_size; ++i) {
		printf("%2i ", *(p + i));
	}

	return 0;
}