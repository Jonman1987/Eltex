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