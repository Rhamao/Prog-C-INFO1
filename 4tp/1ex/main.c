#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(int argc, char *argv[])
{
  stack_init();
  stack_push(5);
  stack_push(7);
  stack_display();
  stack_pop();
  stack_display();
  stack_push(17);
  printf("size = %d, top = %d, got element 0 = %d\n", stack_size(), stack_top(), stack_get_element(0));
  
  return EXIT_SUCCESS;
}
