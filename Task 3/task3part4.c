#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array_size = 10;
	char array[array_size];

	fgets(array, array_size, stdin);
	puts(array);

	char *p = &array[0];

	//scanf("%c", *array);

	printf("Result:\n");

	for (int i = 0; i < array_size; ++i) {
		printf("%c ", *(p + i));
	}

	return 0;
}