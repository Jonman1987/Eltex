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