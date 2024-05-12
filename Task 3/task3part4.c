#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array_size = 50;

	char array1[array_size];
	char array2[array_size];

	printf("Please, enter first string. Length of string less then %i\n", array_size);

	fgets(array1, array_size, stdin);

	char *p1 = &array1[0];

	printf("Please, enter serching string. Length of string less then %i\n", array_size);

	fgets(array2, array_size, stdin);

	char *p2 = &array2[0];

	printf("String 1: ");

	int first_string_size = 0;
	int current_position = 0;

	while(p1[current_position] != '\n') {
		current_position++;
		first_string_size++;
	}

	for (int i = 0; i < first_string_size; ++i) {
		printf("%c", *(p1 + i));
	}

	printf("\nString 2: ");

	int second_string_size = 0;
	current_position = 0;

	while(p2[current_position] != '\n') {
		current_position++;
		second_string_size++;
	}

	for (int i = 0; i < second_string_size; ++i) {
		printf("%c", *(p2 + i));
	}

	printf("\nResult:");

	int j = 0;
	char *ptr = NULL;
	int has_result = 0;

	for (int i = 0; i < first_string_size; ++i) {
		if(*(p1 + i) != *(p2 + j)) {
			j = 0;
			continue;
		}

		if(j == 0) {
			ptr = p1 + i;
		}

		if(j == second_string_size - 1) {
			has_result = 1;
			break;
		}

		j++;
	}

	if(has_result == 1) {
		printf(" Substring was found: %c\n", *ptr);
	} else {
		ptr = NULL;
		printf(" Substring not found\n");
	}
	
	return 0;
}