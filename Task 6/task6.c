#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRUCT_FIELD_SIZE 10

struct abonent;

int CreateNewRecord(struct abonent **array, int *records_count);
int DeleteRecord(struct abonent **array, int *records_count);
int GetRecord(struct abonent **array, int *records_count, int field_length);
int PrintAllRecords(struct abonent **array, int *records_count);
int GetMenuValue();
void PrintLogs();

struct abonent {
		char name[STRUCT_FIELD_SIZE];
		char second_name[STRUCT_FIELD_SIZE];
		char tel[STRUCT_FIELD_SIZE];
	};

int main(int argc, char const *argv[]) {
	int records_count = 0;
	int menu_value = 0;
	int has_error = 0;
	
	struct abonent *array = NULL;
	
	while (menu_value != 9) {
		menu_value = GetMenuValue();

		switch(menu_value) {
			case 1: 
				if(CreateNewRecord(&array, &records_count) > 0) {
					has_error = 1;
				}

				break;

			case 2:
				if(DeleteRecord(&array, &records_count) > 0) {
					has_error = 1;
				}
				
				break;

			case 3:
				GetRecord(&array, &records_count, STRUCT_FIELD_SIZE);

				break;

			case 4:
				PrintAllRecords(&array, &records_count);

				break;

			case 5: 
				menu_value = 9;

				if(has_error == 1) {
					PrintLogs();
				}

				break;

			default: 
				printf("Menu input error.\n");
				menu_value = 0;
		}
	}

	return 0;
}

int CreateNewRecord(struct abonent **array, int *records_count) {
	system("clear");

	array[*records_count] = malloc(1 * sizeof(struct abonent));

	printf("Please, input not more than 9 symbols.\n");
	printf("Input name: ");
	scanf("%s", array[*records_count]->name);
	(*array[*records_count]).name[9] = '\0';

	printf("Input second name: ");
	scanf("%s", array[*records_count]->second_name);
	(*array[*records_count]).second_name[9] = '\0';

	printf("Input telephone: ");
	scanf("%s", array[*records_count]->tel);
	(*array[*records_count]).tel[9] = '\0';
			
	(*records_count)++;

	return 0;
}

int PrintAllRecords(struct abonent **array, int *records_count) {
	system("clear");
	int is_record_found_without_deleted = 0;

	if(*records_count == 0) {
		printf("There are no records.");

		return -1; // Not error. Exit without result of print.
	}
		
	for(int i = 0; i < *records_count; i++) {
		printf("Record %i\n", i + 1);
		printf("Name: ");
		printf("%s", (*array[i]).name);
		printf("\n");

		printf("Second name: ");
		printf("%s", (*array[i]).second_name);
		printf("\n");

		printf("Telephone: ");
		printf("%s", (*array[i]).tel);
		printf("\n\n");

		is_record_found_without_deleted = 1;
	}

	if(is_record_found_without_deleted == 0) {
		printf("There are no records.");

		return -1; // Not error. Exit without result of print.
	}

	return 0;
}

int GetMenuValue() {
	int input_value = 0;

	printf("\nMenu:\n");
	fflush(stdout);
	printf("1 - Add abonent\n");
	printf("2 - Delete abonent\n");
	printf("3 - Find abonent by name\n");
	printf("4 - Print all records\n");
	printf("5 - Exit\n");

	if(scanf("%i", &input_value) != 1) {
		while(fgetc(stdin) != '\n') {
			continue;
		}	
	}

	return input_value;
}

int DeleteRecord(struct abonent **array, int *records_count) {
	system("clear");

	if(*records_count == 0) {
		printf("There are no records for delete.");

		return 1; // Error status code.
	}

	int deleted_position = 0;
	int is_need_delete = 0;

	printf("Please, input record number for delete:");
	scanf("%i", &deleted_position);

	if(deleted_position < 1 || deleted_position > *records_count) {
		printf("Error. Record number must be greater than 1 and less than %i.", *records_count);

		return 1; // Error status code.
	}

	printf("Record %i\n", deleted_position);
	printf("Name: ");
	printf("%s", array[deleted_position - 1]->name);
	printf("\n");

	printf("Second name: ");
	printf("%s", array[deleted_position - 1]->second_name);
	printf("\n");

	printf("Telephone: ");
	printf("%s", array[deleted_position - 1]->tel);
	printf("\n\n");

	printf("Would you like delete this record?\n");
	printf("Please, input: 0 - No, 1 - Yes: ");
	scanf("%i", &is_need_delete);

	if(is_need_delete != 0 && is_need_delete != 1) {
		printf("Error. You input wrong deleted menu number.\n");

		return 3; // Error status code.
	}

	if(is_need_delete == 0) {
		return -1; // Not error. Exit without delete.
	}

	struct abonent deleted_element;

	strcpy(deleted_element.name, array[deleted_position - 1]->name);
	strcpy(deleted_element.second_name, array[deleted_position - 1]->second_name);
	strcpy(deleted_element.tel, array[deleted_position - 1]->tel);

	for(int i = deleted_position - 1; i < *records_count - 1; i++) {
		strcpy(array[i]->name, array[i + 1]->name);
		strcpy(array[i]->second_name, array[i + 1]->second_name);
		strcpy(array[i]->tel, array[i + 1]->tel);
	}

	strcpy(array[*records_count - 1]->name, deleted_element.name);
	strcpy(array[*records_count - 1]->second_name, deleted_element.second_name);
	strcpy(array[*records_count - 1]->tel, deleted_element.tel);

	free(array[*records_count - 1]);

	(*records_count)--;

	return 0;
}

int GetRecord(struct abonent **array, int *records_count, int field_length) {
	system("clear");
	int is_record_found = 0;
	char searched_name[field_length];
			
	printf("Please, input name for search record: ");
	scanf("%s", searched_name);

	for(int i = 0; i < *records_count; i++) {
		if(strcmp(array[i]->name, searched_name) == 0) {
			printf("Record %i\n", i + 1);
			printf("Name: ");
			printf("%s", array[i]->name);
			printf("\n");

			printf("Second name: ");
			printf("%s", array[i]->second_name);
			printf("\n");

			printf("Telephone: ");
			printf("%s", array[i]->tel);
			printf("\n\n");

			is_record_found = 1;
		}
	}

	if(!is_record_found) {
		printf("Record was not found.");

		return -1; // Not error. Exit without result of search.
	}

	return 0;
}

// Function for develop. Can addition print into file.
void PrintLogs() {
	printf("\nErrors occurred during the exicution of the program.\n");
}