#include <ctype.h>
#include <stdio.h>
#include "getch.h"

int getfloat(float *);

int main(void)
{
  float x;
  float *f;
  f = &x;
  getfloat(f);
  printf("f: %g\n", *f);
  return 0;
}


int getfloat(float *fp)
{
  int c, sign, power;
  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  if (c == '+' || c == '-') {
    sign = (c == '+' ? 1: -1);
    c = getch();
    if (!isdigit(c)) {
      if (sign == '-')
        ungetch('-');
      else
        ungetch('+');
      ungetch(c);
      return 0;
    }
  }
  for (*fp = 0; isdigit(c); c = getch())
    *fp = 10 * *fp + (c - '0');
  if (c == '.') {
    c = getch();
    if (!isdigit(c)) {
      ungetch('.');
      ungetch(c);
      return 0;
    }
  }
  for (power = 1;isdigit(c); c = getch()) {
    *fp = 10 * *fp + (c - '0');
    power *= 10;
  }
  *fp = *fp / power;
  if (sign == 1 || sign == -1)
    *fp *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
