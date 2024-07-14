#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createnewrecord.h"
#include "deleterecord.h"
#include "getrecord.h"
#include "printallrecords.h"
#include "getmenuvalue.h"

#define STRUCT_FIELD_SIZE 10

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