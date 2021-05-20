#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "list.h"

	int
main (int argc, char *argv[])
{
	int i;
	int age;
	char *first_name;
	char *last_name;
	List l = NULL;
	FILE *filePointer;

	char dataToBeRead[50];

	filePointer = fopen ("liste_nom.txt", "r");

	if (filePointer == NULL)
		printf ("File failed to open.");

	else
	{
		printf ("The file is beeing read.\n");
		while (fgets (dataToBeRead, 50, filePointer) != NULL)
		{
			char *token = strtok (dataToBeRead, " ");

			for (i = 0; i < 3 && token != NULL; i++)
			{
				if(i==0)first_name = token;
				if(i==1)last_name = token;
				if(i == 2){
					sscanf(token, "%d", &age);
				}
				token = strtok (NULL, " ");
			}
			Cell* c  = create_cell(first_name, last_name, age);
			printf("%s %s %d\n", c->first_name, c->last_name, c->age);
			l = ordered_insertion(l, c, age_order);	
		}

		printf ("The file is read.\n");

		printf ("The file is beeing closed.\n");
		fclose (filePointer);
		printf ("The file is closed.\n");


		print_list(l);
	}
	return 0;
}
