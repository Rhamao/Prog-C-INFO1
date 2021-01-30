#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int *merge_sort(int *t)
{
        int *t1;
        int *t2;
        int size = array_size(t);

        if (size <= 1)
                return t;

        split_arrays(t, &t1, &t2);
        printf("-> Array before sort\n");
        print_array(t);

        printf("-> Split 1\n");
        print_array(t1);

        printf("-> Split 2\n");
        print_array(t2);

        return merge_sorted_arrays(t1, t2);
}

void split_arrays(int *t, int **t1, int **t2)
{
        int i, size, mid;
        size = array_size(t);
        mid = size / 2;

        if (size % 2 != 0)
        {
                *t1 = create_array(mid + 1);
                *t2 = create_array(mid);
                *(t1[0] + mid) = -1;
                *(t2[0] + mid - 1) = -1;
        }
        else
        {
                *t1 = create_array(mid);
                *t2 = create_array(mid);
                *(t1[0] + mid) = -1;
                *(t2[0] + mid) = -1;
        }

        for (i = 0; i < mid; i++)
                *(t1[0] + i) = t[i];
        for (i = mid; i < size; i++)
                *(t2[0] + i - mid) = t[i];

        t1[mid] = -1;
        t2[size] = -1;
}

int *merge_sorted_arrays(int *t1, int *t2)
{
        int *t = NULL;
        int size;
        t = concat_array(t1, t2);
        size = array_size(t);

        qsort(t, size, sizeof(int), compare);

        return t;
}

int *concat_array(int *t1, int *t2)
{
        int i;
        int *t12 = NULL;
        int size1 = array_size(t1);
        int size2 = array_size(t2);

        t12 = (int *)malloc(sizeof(int) * (size1 + size2 + 1));

        for (i = 0; i < size1; i++)
        {
                t12[i] = t1[i];
        }
        for (i = size1; i < size1 + size2; i++)
        {
                t12[i] = t2[i - size1];
        }

        t12[size1 + size2] = -1;

        return t12;
}

int *fill_array(void)
{
        int i;
        int buff;
        int size;
        int *t = NULL;
        printf("Interger tab size : ");
        scanf("%d", size);
        t = create_array(size);
        for (i = 0; i < size; i++)
        {
                printf("%i : ", i);
                scanf("%d", buff);
                t[i] = buff;
        }
        t[size] = -1;
        return t;
}

/* return lentgh before finding -1 value*/
int array_size(int *t)
{
        int size = 0;
        while (t[size++] != -1)
                ;
        size--;
        return size;
}

int *create_array(int size)
{
        int *t = (int *)malloc(size * sizeof(int) + 1);
        if (t == NULL)
        {
                printf("Problème allocation mémoire\n");
                exit(EXIT_FAILURE);
        }
        t[size] = -1;
        return t;
}

void print_array(int t[])
{
        int i = 0;
        printf("[ ");
        while (t[i] != -1)
                printf("%d ", t[i++]);
        printf("]\n");
}

int *copy_array(int src[])
{
        int i;
        int size = array_size(src);
        int *dst = NULL;
        dst = create_array(size);
        for (i = 0; i < size; i++)
        {
                dst[i] = src[i];
        }
        return dst;
}

void random_array(int t[], int max_value)
{
        int i;
        int size = array_size(t);
        for (i = 0; i < size; i++)
                t[i] = rand() % max_value;
        t[size] = -1;
}

/**
 * Initialises the array t with a random permutation of
 *   the values 0, 1, ..., size-1.
 * Uses the Knuth shuffle:
 *   https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 */
void fill_random_permutation(int t[], int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
                int j = rand() % (i + 1);
                t[i] = t[j];
                t[j] = i;
        }
}

int are_array_equal(int t1[], int t2[])
{
        int i;
        if (array_size(t1) != array_size(t2))
                return 0;
        for (i = 0; i < sizeof(t1) / sizeof(int); i++)
                if (t1[i] != t2[i])
                        return 0;
        return 1;
}

void free_table(int *t)
{
        free(t);
        return;
}

int compare(const void *a, const void *b)
{
        int aint = *(int *)a;
        int bint = *(int *)b;
        if (aint == bint)
                return 0;
        else if (aint < bint)
                return -1;
        else
                return 1;
}
