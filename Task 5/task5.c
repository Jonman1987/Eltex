#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRUCT_FIELD_SIZE 100 

struct abonent;

int CreateNewRecord(struct abonent **current_ptr, int *records_count, int array_length);
int DeleteRecord(struct abonent **start_ptr, int *records_count, int field_length, const char *deleted_name);
int GetRecord(struct abonent **start_ptr, int *records_count, int field_length, const char *deleted_name);
int PrintAllRecords(struct abonent **start_ptr, int *records_count, const char *deleted_name);
int GetMenuValue();
void PrintLogs();

struct abonent {
		char name[STRUCT_FIELD_SIZE];
		char second_name[STRUCT_FIELD_SIZE];
		char tel[STRUCT_FIELD_SIZE];
	};

int main(int argc, char const *argv[])
{
	int array_length = 100;
	int records_count = 0;
	
	int menu_value = 0;
	int field_length = 10;
	int has_error = 0;
	
	struct abonent array[array_length];
	struct abonent *start_ptr = &array[0];
	struct abonent *current_ptr = start_ptr;
	
	char const deleted_name[] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};
	
	while (menu_value != 9) {
		menu_value = GetMenuValue();

		switch(menu_value) {
			case 1: 
				if(CreateNewRecord(&current_ptr, &records_count, array_length) > 0){
					has_error = 1;
				}

				break;

			case 2:
				if(DeleteRecord(&start_ptr, &records_count, field_length, deleted_name) > 0){
					has_error = 1;
				}
				
				break;

			case 3:
				GetRecord(&start_ptr, &records_count, field_length, deleted_name);

				break;

			case 4:
				PrintAllRecords(&start_ptr, &records_count, deleted_name);

				break;

			case 5: 
				menu_value = 9;

				if(has_error == 1){
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

int CreateNewRecord(struct abonent **current_ptr, int *records_count, int array_length) {
	if(*records_count == array_length) {
			printf("Array is full.");

			return 1; // Error status code.
		}

	system("clear");
	printf("Please, input not more than 9 symbols.\n");
	printf("Input name: ");
	scanf("%s", (*current_ptr)->name);
	(**current_ptr).name[9] = '\0';

	printf("Input second name: ");
	scanf("%s", (*current_ptr)->second_name);
	(**current_ptr).second_name[9] = '\0';

	printf("Input telephone: ");
	scanf("%s", (*current_ptr)->tel);
	(**current_ptr).tel[9] = '\0';
			
	(*records_count)++;
	(*current_ptr)++;

	return 0;
}

int DeleteRecord(struct abonent **start_ptr, int *records_count, int field_length, const char *deleted_name) {
	system("clear");

	int deleted_position = 0;
	int is_need_delete = 0;

	printf("Please, input record number for delete:");
	scanf("%i", &deleted_position);

	if(deleted_position < 1 || deleted_position > *records_count) {
		printf("Error. Record number must be greater than 1 and less than %i.", *records_count);

		return 1; // Error status code.
	}

	if(strcmp(((*start_ptr) + (deleted_position - 1))->name, deleted_name) == 0) {
		printf("Error. This record was deleted early.");

		return 2; // Error status code.
	}

	printf("Record %i\n", deleted_position);
	printf("Name: ");
	printf("%s", ((*start_ptr) + (deleted_position - 1))->name);
	printf("\n");

	printf("Second name: ");
	printf("%s", ((*start_ptr) + (deleted_position - 1))->second_name);
	printf("\n");

	printf("Telephone: ");
	printf("%s", ((*start_ptr) + (deleted_position - 1))->tel);
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

	for(int i = 0; i < field_length - 1; i++) {
		((*start_ptr) + deleted_position - 1)->name[i] = '0';
		((*start_ptr) + deleted_position - 1)->second_name[i] = '0';
		((*start_ptr) + deleted_position - 1)->tel[i] = '0';
	}

	((*start_ptr) + deleted_position - 1)->name[field_length - 1] = '\0';
	((*start_ptr) + deleted_position - 1)->second_name[field_length - 1] = '\0';
	((*start_ptr) + deleted_position - 1)->tel[field_length - 1] = '\0';

	return 0;
}

int GetRecord(struct abonent **start_ptr, int *records_count, int field_length, const char *deleted_name) {
	system("clear");
	int is_record_found = 0;
	char searched_name[field_length];
			
	printf("Please, input name for search record: ");
	scanf("%s", searched_name);

	if(strcmp(searched_name, deleted_name) == 0) {
		printf("Warning! Maybe you try to search deleted position.\n");
	}

	for(int i = 0; i < *records_count; i++) {
		if(strcmp(((*start_ptr) + i)->name, searched_name) == 0) {
			printf("Record %i\n", i + 1);
			printf("Name: ");
			printf("%s", ((*start_ptr) + i)->name);
			printf("\n");

			printf("Second name: ");
			printf("%s", ((*start_ptr) + i)->second_name);
			printf("\n");

			printf("Telephone: ");
			printf("%s", ((*start_ptr) + i)->tel);
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

int PrintAllRecords(struct abonent **start_ptr, int *records_count, const char *deleted_name){
	system("clear");
	int is_record_found_without_deleted = 0;

	if(*records_count == 0) {
		printf("There are no records.");

		return -1; // Not error. Exit without result of print.
	}
		
	for(int i = 0; i < *records_count; i++) {
		if(strcmp(((*start_ptr) + i)->name, deleted_name) == 0) {
			continue;
		}

		printf("Record %i\n", i + 1);
		printf("Name: ");
		printf("%s", ((*start_ptr) + i)->name);
		printf("\n");

		printf("Second name: ");
		printf("%s", ((*start_ptr) + i)->second_name);
		printf("\n");

		printf("Telephone: ");
		printf("%s", ((*start_ptr) + i)->tel);
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

		if(scanf("%i", &input_value) != 1){
			while(fgetc(stdin) != '\n'){
				continue;
			}	
		}

		return input_value;
}

// Function for develop. Can addition print into file.
void PrintLogs() {
	printf("\nErrors occurred during the exicution of the program.\n");
}