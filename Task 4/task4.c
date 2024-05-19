#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int field_length = 10;

	struct abonent {
		char name[field_length];
		char second_name[field_length];
		char tel[field_length];
	};

	int array_length = 100;
	struct abonent array[array_length];
	int menu_value = 0;
	int records_count = 0;
	struct abonent *start_ptr = &array[0];
	struct abonent *current_ptr = start_ptr;
	int deleted_position = 0;
	int is_need_delete = 0;
	char searched_name[field_length];

	while (menu_value != 9) {
		printf("\nMenu:\n");
		fflush(stdout);
		printf("1 - Add abonent\n");
		printf("2 - Delete abonent\n");
		printf("3 - Find abonent by name\n");
		printf("4 - Print all records\n");
		printf("5 - Exit\n");

		scanf("%i", &menu_value);

		switch(menu_value) {
			case 1: 

				if(records_count == array_length) {
					printf("Array is full.");
					break;
				}

				system("clear");
				printf("Input name: ");
				scanf("%s", current_ptr -> name);

				printf("Input second name: ");
				scanf("%s", current_ptr -> second_name);

				printf("Input telephone: ");
				scanf("%s", current_ptr -> tel);
			
				records_count++;
				current_ptr++;

				break;

			case 2: 
				system("clear");
				printf("Please, input record number for delete:");
				scanf("%i", &deleted_position);

				printf("Record %i\n", deleted_position);
				printf("Name: ");
				printf("%s", (start_ptr + (deleted_position - 1)) -> name);
				printf("\n");

				printf("Second name: ");
				printf("%s", (start_ptr + (deleted_position - 1)) -> second_name);
				printf("\n");

				printf("Telephone: ");
				printf("%s", (start_ptr + (deleted_position - 1)) -> tel);
				printf("\n\n");

				printf("Would you like delete this record?\n");
				printf("Please, input: 0 - No, 1 - Yes: ");
				scanf("%i", &is_need_delete);

				if(is_need_delete == 0){
					break;
				}

				for(int i = 0; i < field_length - 1; i++){
					(start_ptr + deleted_position - 1) -> name[i] = '0';
					(start_ptr + deleted_position - 1) -> second_name[i] = '0';
					(start_ptr + deleted_position - 1) -> tel[i] = '0';
				}

				(start_ptr + deleted_position - 1) -> name[field_length - 1] = '\0';
				(start_ptr + deleted_position - 1) -> second_name[field_length - 1] = '\0';
				(start_ptr + deleted_position - 1) -> tel[field_length - 1] = '\0';
				
				break;

			case 3: 
				system("clear");
				printf("Please, input name for search record: ");
				scanf("%s", searched_name);

				for(int i = 0; i < records_count; i++){
					if(strcmp((start_ptr + i) -> name, searched_name) == 0){
						printf("Record %i\n", i + 1);
						printf("Name: ");
						printf("%s", (start_ptr + i) -> name);
						printf("\n");

						printf("Second name: ");
						printf("%s", (start_ptr + i) -> second_name);
						printf("\n");

						printf("Telephone: ");
						printf("%s", (start_ptr + i) -> tel);
						printf("\n\n");
					}
				}

				break;

			case 4: 
				system("clear");

				for(int i = 0; i < records_count; i++){
					printf("Record %i\n", i + 1);
					printf("Name: ");
					printf("%s", (start_ptr + i) -> name);
					printf("\n");

					printf("Second name: ");
					printf("%s", (start_ptr + i) -> second_name);
					printf("\n");

					printf("Telephone: ");
					printf("%s", (start_ptr + i) -> tel);
					printf("\n\n");
				}

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