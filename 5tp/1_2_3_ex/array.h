#ifndef ARRAY_H
#define ARRAY_H

int* merge_sort(int* t);

void split_arrays(int* t, int** t1, int** t2);

int* concat_array(int t1[], int t2[]);

int* fill_array(void); 

/* return lentgh before finding -1 value*/
int array_size(int* t);

/* I use free_integer_array() instead of void free_integer_array(int* tab); */
void free_table(int *t);

/*I use create_array() instead of int* allocate_integer_array(int size);*/
int* create_array(int size);

void print_array(int t[]);

int* copy_array(int src[]);

void random_array(int t[], int max_value);

void fill_random_permutation(int t[], int size);

void fill_twin_tabs(int t1[], int t2[], int size);

int are_array_equal(int t1[], int t2[]);

int compare(const void *a, const void *b);

int* merge_sorted_arrays(int* t1, int* t2);

#endif /* ARRAY_H */
