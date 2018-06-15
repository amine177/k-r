#include <stdio.h>


int main(void)
{
  int c, i, nother, nwhite;
  int ndigit[10];

  nother = nwhite = 0;
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9')
      ++ndigit[c-'0'];
    else if ( c == ' ' || c == '\t' || c == '\n')
      ++nwhite;
    else
      ++nother;

  printf("digits =");
  for (i = 0; i < 10; ++i)
    printf(" '%c':%d", '0' + i, ndigit[i]);
  printf(", white space = %d, other = %d\n",
      nwhite, nother);

  return 0;
}
