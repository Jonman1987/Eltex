#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getmenuvalue.h"
#include "inputnumbers.h"

int main(int argc, char const *argv[])
{
	int menu_value = 0;
	int first_number = 0;
	int second_number = 0;

	while (menu_value != 9) {
		menu_value = GetMenuValue();
		printf("\n");

		switch(menu_value) {
			case 1: 
				InputNumbers(&first_number, &second_number);
				Addition(&first_number, &second_number);
				
				break;

			case 2:
				InputNumbers(&first_number, &second_number);
				Substraction(&first_number, &second_number);
				
				break;

			case 3:
				InputNumbers(&first_number, &second_number);
				Multiplication(&first_number, &second_number);

				break;

			case 4:
				InputNumbers(&first_number, &second_number);
				Division(&first_number, &second_number);

				break;

			case 5: 
				menu_value = 9;

				break;

			default: 
				printf("Menu input error.\n");
				menu_value = 0;
		}
	}
	
	return 0;
}