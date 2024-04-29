#include <stdio.h>

int main(int argc, char const *argv[])
{
	int tmp_number = 255;
	int changeable_number;
	

	printf("Please, input a positive integer number in decimal system, which will be changed: ");
	fflush(stdout);

	scanf("%i", &changeable_number);

	printf("First number before change: ");


	for (int i = sizeof(changeable_number) * 8 - 1; i >= 0; i--) {
		printf("%i", (changeable_number >> i) & 1);

		if(i % 8 == 0 && i != 0) {
			printf(" ");
		}
	}

	int change_number;

	printf("\n\nPlease, input a positive integer number in decimal system, which change: ");


	scanf("%i", &change_number);

	printf("Second number before change: ");

	for (int i = sizeof(change_number) * 8 - 1; i >= 0; i--) {
		printf("%i", (change_number >> i) & 1);

		if(i % 8 == 0 && i != 0) {
			printf(" ");
		}
	}

	tmp_number = (tmp_number << 16);
	tmp_number = ~tmp_number;
	changeable_number = changeable_number & tmp_number;
	tmp_number = ~tmp_number;
	change_number = (change_number << 16);
	change_number = change_number & tmp_number;
	changeable_number = changeable_number | change_number;

	printf("\n\nResult: ");

	for (int i = sizeof(changeable_number) * 8 - 1; i >= 0; i--) {
		printf("%i", (changeable_number >> i) & 1);

		if(i % 8 == 0 && i != 0) {
			printf(" ");
		}
	}
	

	return 0;
}