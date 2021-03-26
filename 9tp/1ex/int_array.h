#ifndef INT_ARRAY_H
#define INT_ARRAY_H
/**
 * Allocation d'un tableau
 */
int* create_int_array(int size);

void print_int_array(int *t, int size); 

/**
 * Libération d'un tableau
 */
void free_int_array(int *t);

/**
 * Remplissage d'un tableau par des entiers
 * démarrant à 1 puis incrémentés
 */ 
void fill_array(int *t, int size);

#endif /*INT_ARRAY_H*/