#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "char2d_array.h"


/**
 * Allocation d'un tableau
 */
char** create_char2d_array(int n, int m){
	int i;
	char** t;

	t=(char**)malloc(n*sizeof(char*));

	for(i=0; i<n; i++)
		t[i] = (char*)malloc(m*sizeof(char));

	return t;
}

void print_char2d_array(char **t, int n, int m){
	int i, j;
	for(i = 0; i<n; i++){
		for(j = 0; j<m; j++){
			printf("%c ", t[i][j]);
		}
		printf("\n");
	}
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

/**
 * Remplissage d'un tableau par des entiers
 * démarrant à 1 puis incrémentés
 */ 
void fill_char2d_array(char **t, int n, int m){
	int offset = 0; 
	int i, j;
	char buff;

	for(i = 0; i<n; i++){
		for(j = 0; j<m; j++){
			if(offset > 25){
				offset = 0;
			}
			buff = 'a' + offset;
			t[i][j] = buff;
			offset++;
		}
	}
}