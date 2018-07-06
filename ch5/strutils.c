#include <stdio.h>


void strcatutil(char *s, char *t)
{
  while (*++s)
    ;
  while (*t)
    *s++ = *t++;
  *s = '\0';
}

int strendutil(char *s, char *t)
{
  char *i;
  char *r1, *r2;
  int n, l;

  r1 = s;
  r2 = t;
  n = 0;
  while (*t++)
    n++;
  l = 0;
  while (*s++)
    l++;
  s = r1;
  t = r2;
  for (i = s + l - n; *i = *t; i++, t++)
    if (*i != *t)
      return 0;
  return 1;
}
