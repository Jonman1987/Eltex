#include <stdio.h>

int main(int argc, char const *argv[])
{
	int matrix_size = 10;
	int matrix[matrix_size];
	int *p = &matrix[0];

	for (int i = 0, matrix_value = 1; i < matrix_size; ++i, ++matrix_value) {
		matrix[i] = matrix_value;
	}

	printf("Result:\n");

	for (int i = 0; i < matrix_size; ++i) {
		printf("%2i ", *p + i);
	}

	return 0;
}