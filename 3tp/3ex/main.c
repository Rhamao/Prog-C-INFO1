#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

const char *evaluate(char *str);
bool is_num(char *str);
int is_char(char *str);
int power_rec(int a, unsigned int n);
const char *decToHexa(int n);
void reverse(char t[], int lo, int hi);
void swap(char *a, char *b);

int main(int argc, char *argv[])
{
  printf("%s\n", evaluate("676"));
  printf("%s\n", evaluate("abc"));
  printf("%s\n", evaluate("A?2"));
  return EXIT_SUCCESS;
}

const char *evaluate(char *str)
{
  char *str_out = malloc(100);
  int nb_in_dec = 0;
  int n = 0;
  int buff;
  int size;
  size = is_char(str);
  if (size != -1)
  {
    while (*str)
    {
      n++;
      buff = (int)*str;
      buff = buff - 97;
      buff = buff * power_rec(26, size - n);
      nb_in_dec += buff;
      /*Pointing to next char*/
      str++;
    }
    sprintf(str_out, "%d", nb_in_dec);
  }
  else if (is_num(str))
  {
    sprintf(str_out, "%s", decToHexa(atoi(str)));
  }
  else
  {
    return "err";
  }

  return str_out;
}

int is_char(char *str)
{
  int size = 0;
  while (*str)
  {
    if (!(*str >= 'a' && 'z' >= *str))
      return -1;
    size++;
    /*Pointing to next char*/
    str++;
  }
  return size;
}

bool is_num(char *str)
{
  while (*str)
  {
    if (!(*str >= '0' && '9' >= *str))
      return false;
    /*Pointing to next char*/
    str++;
  }
  return true;
}

int power_rec(int a, unsigned int n)
{
  if (n != 0)
    return (a * power_rec(a, n - 1));
  else
    return 1;
}

const char *decToHexa(int n)
{
  char *str_out = malloc(100);

  int i = 0;
  while (n != 0)
  {
    int temp = 0;

    temp = n % 26;

    str_out[i] = temp + 97;
    i++;

    n = n / 26;
  }
  reverse(str_out, 0, strlen(str_out)-1);
  return str_out;
}

void reverse(char t[], int lo, int hi)
{
  char buff;
  for (; lo <= hi; lo += 1, hi -= 1)
  {
    buff = t[lo];
    t[lo] = t[hi];
    t[hi] = buff;
  }
}
