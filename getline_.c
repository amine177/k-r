#include <stdio.h>
#include "getline_.h"

int getline_(char s[], int m)
{
  int i = 0;
  int c;

  while (i < m && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
