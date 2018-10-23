#include <stdio.h>
/*A program to count digits, whitespaces
 * and other chars..*/


int main(void)
{
  int c, i, nother, nwhite;
  int ndigit[10] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
  };

  nother = nwhite = 0;
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
  printf(", whitespaces = %d, other = %d\n",
      nwhite, nother);

  return 0;
}
