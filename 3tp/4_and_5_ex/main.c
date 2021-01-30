#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int dichotomy(int *tab, int elt, int lo, int hi);
void bubbleSort(int *tab, int n);

int main(int argc, char *argv[])
{
  int size=30;
  int max_value = 100;
	int *t1 = NULL, *t2 = NULL, *t3=NULL;

	t1 = create_array(size);
	fill_random_array(t1, size, max_value);
  t2 = create_array(size);
	fill_random_array(t2, size, max_value);
  t3 = create_array(size);
	fill_random_array(t3, size, max_value);

  printf("Avant le tri :\n");
  print_array(t1, size);
  print_array(t2, size);
  print_array(t3, size);

  bubbleSort(t1, size);
  bubbleSort(t2, size);
  bubbleSort(t3, size);

  printf("Apres le tri :\n");
  print_array(t1, size);
  print_array(t2, size);
  print_array(t3, size);


  return EXIT_SUCCESS;
}

int dichotomy(int *tab, int elt, int lo, int hi)
{
  int mid = (lo + hi) / 2;

  if (!(lo < hi))
    return EXIT_FAILURE;

  if (elt > tab[mid])
    return dichotomy(tab, elt, mid + 1, hi);
  else if (elt < tab[mid])
    return dichotomy(tab, elt, lo, mid - 1);
  else
    return mid;
}

void bubbleSort(int *tab, int size) 
{ 
   int i, j; 
   for (i = 0; i < size-1; i++)        
       for (j = 0; j < size-i-1; j++)  
           if (tab[j] > tab[j+1]) 
              swap(&tab[j], &tab[j+1]); 
} 