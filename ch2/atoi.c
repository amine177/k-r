#include <stdio.h>


int atoi(char[]);

int main()
{
  char *s = "129";
  printf("%d\n", atoi(s));
  return 0;
}

int atoi(char s[])
{
  int i, res;

  i = 0;
  res = 0;
  while (s[i] >= '0' && s[i] <= '9')
    res = 10 * res + (s[i++] - '0');

  return res;
}
