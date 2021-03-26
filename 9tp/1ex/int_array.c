#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "int_array.h"


/**
 * Allocation d'un tableau
 */
int* create_int_array(int size){
	int* t;
	t = (int*) malloc(size*sizeof(int));
	if(t==NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(1);
	}
	return t;
}

void print_int_array(int *t, int size){
	int i;
	printf("[");
	for (i = 0; i < size; i++)
	    printf(" %d ", t[i]);
	printf(" ]");   
}

/**
 * Libération d'un tableau
 */
void free_int_array(int *t){
	if(!(t==NULL))
		free(t);
}

/**
 * Remplissage d'un tableau par des entiers
 * démarrant à 1 puis incrémentés
 */ 
void fill_array(int *t, int size){
	int i;
	for (i = 0; i < size; i++)
		t[i] = i + 1;
}