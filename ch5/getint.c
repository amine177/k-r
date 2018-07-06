#include <ctype.h>
#include <stdio.h>
#include "getch.h"

int getint(int *);

int main(void)
{
  int n = -1;
  int *pn;
  getint(&n);
  printf("\n%d", n);
  return 0;
}

int getint(int *pn)
{
  int c, sign, sig;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = ( c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
  }
  if (!isdigit(c)) {
    ungetch(c);
    if (sign == -1 || sign == 1)
      ungetch(sign == 1 ? '+': '-');
    return 0;
  }
  for (*pn = 0; isdigit(c); c = getch()) 
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if ( c != EOF)
    ungetch(c);
  return c;
}
