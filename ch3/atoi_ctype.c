#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100

int atoi_mine(char[]);

int main(void)
{
  char s[MAXLENGTH];
  char **endptr;
  int i = 0;
  while ((s[i++] = getchar()) != EOF)
    ;
  printf("atoi_mine: %d\n", atoi_mine(s));
  printf("atoi: %d\n", atoi(s));
  printf("strtol: %ld\n", strtol(s, endptr, 16));
}
int atoi_mine(char s[])
{
  int i, n , sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1: 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');
  return sign * n;
}
