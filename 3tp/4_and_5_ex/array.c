#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int* create_array(int size) {
	int* t = (int*) malloc(size * sizeof(int));	
	if(t == NULL) {
		printf("Problème allocation mémoire\n");
		exit(EXIT_FAILURE);
	}
	return t;
}

void print_array(int t[], int size) {
	int i;
	printf("[");
	for(i=0;i<size-1;i++) {
		printf("%d, ",t[i]);	
	}
	if(size>0)
		printf("%d",t[size-1]);
	printf("]\n");
	
}

void fill_random_array(int t[], int size, int max_value) {
	int i;
	for(i=0; i<size; i++) {
		t[i] = rand()%max_value;
	}
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



