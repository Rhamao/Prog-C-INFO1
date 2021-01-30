#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "stack.h"

static Stack stack;

/* Initialize correctly the stack. */
void stack_init(void)
{
  stack.size = -1;
  *stack.values = (int*) malloc(MAX_SIZE * sizeof(int));
}

/* Returns the current size of the stack. */
int stack_size(void)
{
  return (stack.size + 1);
}

/* Returns 1 if the stack is empty, returns 0 otherwise. */
int stack_is_empty(void)
{
  if (stack.size <= 0)
    return 1;
  return 0;
}

/* Returns the element at the top of the stack. */
int stack_top(void)
{
  if (stack_is_empty())
    return INT_MIN;
  return stack.values[stack.size];
}

/* Pops the element at the top of the stack and returns it. */
int stack_pop(void)
{
  if (stack_is_empty())
    return INT_MIN;
  int buff = stack.values[stack.size];
  /*size is returned then decremented so that works*/
  stack.values[stack.size--] = 0;
  return buff;
}

/* Pushes a given integer `n` at the top of the stack. */
void stack_push(int n)
{
  if (stack.size > 15)
    return;
  stack.values[++stack.size] = n;
}

/* Displays the content of the stack on the standard output. */
void stack_display(void)
{
  int i;
  for (i = 0; i < MAX_SIZE; i++)
    printf("%d ", stack.values[i]);
  printf("\n");
}

/* Returns the element at index `index` inside the stack. The user is
   responsible of the use of this function. The answers may be not
   relevant if a call is done outside the current size of the
   stack. */
int stack_get_element(int index)
{
  if (stack_is_empty() || index > MAX_SIZE)
    return INT_MIN;
  return stack.values[index];
}
