#include <stdio.h>
#include <stdlib.h>

char *getline_(int n)
{
  char *s = malloc(n);
  char c;
  int i;
  while ((c = getchar()) != EOF && c != '\n' && n--) {
    *s++ = c;
    i++;
  }
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s;
}
