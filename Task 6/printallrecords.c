#include <stdio.h>
#include <stdlib.h>
#include "main.h"

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