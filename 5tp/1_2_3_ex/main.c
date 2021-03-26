#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <time.h>

/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char *argv[])
{

  srand(time(NULL));

  int *t1 = NULL, *t2 = NULL, *t12 = NULL, *t3 = NULL, *t4 = NULL, *t = NULL;

  printf("Here are 2 empty arrays :\n");
  t1 = create_array(10);
  t2 = create_array(10);
  print_array(t1);
  print_array(t2);
  putchar('\n');

  printf("I can fill them randomly :\n");
  random_array(t1, 100);
  random_array(t2, 100);
  print_array(t1);
  print_array(t2);
  putchar('\n');

  printf("I can merge and sort them :\n");
  t12 = merge_sorted_arrays(t1, t2);
  print_array(t12);
  putchar('\n');

  free(t1);
  free(t2);

  printf("I can split them back :\n");
  split_arrays(t12, &t3, &t4);
  print_array(t3);
  print_array(t4);
  putchar('\n');

  free(t12);
  free(t3);
  free(t4);

  printf("I can sort an array by splitting it and merge it back :\n");
  t = create_array(20);
  random_array(t, 100);
  t = merge_sort(t);
  printf("-> Result\n");
  print_array(t);

  free(t);
  return 0;
}
