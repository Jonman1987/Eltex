#include <stdio.h>

int main(int argc, char const *argv[])
{
	int matrix_size;

	printf("Please, input a positive integer number equal matrix size: ");
	fflush(stdout);

	scanf("%i", &matrix_size);

	int matrix[matrix_size][matrix_size];

	int start_border = 0;
	int end_border = matrix_size;
	int matrix_value = 1;

	int i = 0;
	int j = 0;

	while (matrix_value <= matrix_size * matrix_size) {
		for (i = start_border; i < end_border; i++) {
			matrix[j][i] = matrix_value;
			matrix_value++;
		}

		j = i - 1;

		for (i = start_border + 1; i < end_border; i++) {
			matrix[i][j] = matrix_value;
			matrix_value++;
		}

		for (i = end_border - 2; i >= start_border; i--) {
			matrix[j][i] = matrix_value;
			matrix_value++;
		}

		j = start_border;


		for (i = end_border - 2; i > start_border; i--) {
			matrix[i][j] = matrix_value;
			matrix_value++;
		}

		start_border++;
		j = start_border;
		end_border--;
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