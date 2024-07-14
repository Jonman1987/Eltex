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