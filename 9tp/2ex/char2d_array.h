#ifndef CHAR2D_ARRAY_H
#define CHAR2D_ARRAY_H
/**
 * Allocation d'un tableau
 */
char** create_char2d_array(int n, int m);

void print_char2d_array(char **t, int n, int m);

/**
 * Libération d'un tableau
 */
void free_char2d_array(char **t, int n);

/**
 * Remplissage d'un tableau par des entiers
 * démarrant à 1 puis incrémentés
 */ 
void fill_char2d_array(char **t, int n, int m);

#endif /*CHAR2D_ARRAY_H*/