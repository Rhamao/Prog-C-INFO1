#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *file_ptr;
	char file_name[100], c;

	printf("Type the name of the source code file : \n");
	scanf("%s", file_name);

	/*Open the file*/
	file_ptr = fopen(file_name, "r");
	if (file_ptr == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	/*Until the file is ended we print each char*/
	c = fgetc(file_ptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(file_ptr);
	}

	/*Close the file*/
	fclose(file_ptr);

	return EXIT_SUCCESS;
}