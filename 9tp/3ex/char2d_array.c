#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "char2d_array.h"


/**
 * Initialisation d'un tableau
 */
char** initialize_char2d_array(int nblines){
	char** t;

	t=(char**)malloc(nblines*sizeof(char*));

	return t;
}

/**
 * Allocate the memory for a new string
 */
char* create_new_line(char* str){
	char* t;

	t = (char*) malloc((strlen(str) + 1) * sizeof(char));
	strcpy(t, str);

	return t;
}


/**
 * Libération d'un tableau
 */
void free_char2d_array(char **t, int n){
	if(t==NULL) 
		return;
	int i;
	for(i=0; i<n; i++)
		if(t[i] != NULL)
			free(t[i]);
	free(t);
}