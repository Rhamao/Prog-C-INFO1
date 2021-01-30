#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLANK_SPACE false
#define WORD true

int wc(char *str);
int is_delimiter(char c);

int main(int argc, char *argv[])
{
  wc("Un deux trois\nQuatre\n\n Cinq six huits a b c\t\t");
  return EXIT_SUCCESS;
}

int wc(char *str)
{
  int chars = 0;
  int words = 0;
  int lines = 0;
  bool current_char = BLANK_SPACE;

  if (*str != NULL)
    lines++;

  while (*str)
  {
    if (is_delimiter(*str))
    {
      current_char = BLANK_SPACE;
      if (*str == '\n')
        lines++;
    }
    else if (current_char == BLANK_SPACE)
    {
      current_char = WORD;
      words++;
      chars++;
    }
    else
    {
      chars++;
    }
    /*pointing next char*/
    str++;
  }

  printf("Nb of chars : %d\n", chars);
  printf("Nb of words : %d\n", words);
  printf("Nb of lines : %d\n", lines);
  return 0;
}

int is_delimiter(char c)
{
  if ((c == ' ') || (c == '\t') || (c == '\n'))
    return 1;
  return 0;
}
