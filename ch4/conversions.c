#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

long atoiconv(char *s)
{
  long n = 0;
  int sign;
  while (isspace(*s++) || *s == '\t')
    ;
  if (*s == '-') {
    sign = 1;
    s++;
  }
  else if (*s == '+')
    s++;
  while(*s >= '0' && *s <= '9') {
    n = 10 * n + (*s - '0');
    s++;
  }
  if (sign)
    n = -n;
  return n;
}

char* itoa(long n)
{
  char *s = malloc(32);
  char *t = s;
  char tmp;
  int i = 0;
  int j;
  int sign = 0;
  if (n < 0) {
    sign = 1;
    n = -n;
  }
  do {
    *s = n % 10 + '0';
    s++;
    i++;
  } while ((n /= 10) > 0);
  if (sign) {
    *s++ ='-';
    i++;
  }
  *s = '\0';
  s = t;
  for ( j = 0; j < i / 2; j++) {
    tmp =  *(s+j);
    *(s+j) = *(s+i-j-1);
    *(s+i-j-1) = tmp;
  }
  return t;
}
