#include <stdio.h>

int getline_(char[], int);

int main()
{
  int lim = 10;
  char s[lim];

  while (getline_(s, lim))
    printf("%s\n", s);

  return 0;
}


int getline_(char s[], int lim)
{
  int i;
  char c;

  i = 0;
  while (i < lim-1) {
    if ((c=getchar()) == '\n')
      break;
    if (c == EOF)
      break;
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}
