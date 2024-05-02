#include <stdio.h>

int main(int argc, char const *argv[])
{
	int matrix_size;

	printf("Please, input a positive integer number equal matrix size: ");
	fflush(stdout);

	scanf("%i", &matrix_size);

	int matrix[matrix_size][matrix_size];

	for (int i = 0, matrix_value = 1; i < matrix_size; ++i) {
		for (int j = 0; j < matrix_size; ++j, ++matrix_value) {
			matrix[i][j] = matrix_value;
		}
	}

	printf("Result:\n");

	for (int i = 0; i < matrix_size; ++i) {
		for (int j = 0; j < matrix_size; ++j) {
			printf("%3i ", matrix[i][j]);
		}

		printf("\n");
	}

	return 0;
}