#ifndef CHAR2D_ARRAY_H
#define CHAR2D_ARRAY_H

/**
 * Initialisation d'un tableau
 */
char** initialize_char2d_array(int nblines);

char* create_new_line(char* str);

/**
 * Libération d'un tableau
 */
void free_char2d_array(char **t, int n);


#endif /*CHAR2D_ARRAY_H*/