#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "list.h"

int main (int argc, char *argv[])
{
	int i;
	int age;
	char *first_name;
	char *last_name;
	List l = NULL;
	List ll = NULL;
	FILE *filePointer;

	char dataToBeRead[50];

	filePointer = fopen ("small_liste_nom.txt", "r");

	if (filePointer == NULL)
		printf ("File failed to open.");

	else
	{
		printf ("\n************************\n");
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
			Cell* cc  = create_cell(first_name, last_name, age);
			/*l = ordered_insertion(l, c, age_order);*/
			ll = double_ordered_insertion(ll, cc, age_order, name_order);
		}

		printf ("The file is read.\n");
		printf ("The file is beeing closed.\n");
		fclose (filePointer);
		printf ("The file is closed.\n");
		printf ("\n************************\n");


		/*print_list(l);*/
		print_list(ll);
	}
	return 0;
}
