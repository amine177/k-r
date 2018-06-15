#include <stdio.h>


int atoi(char s[]);

int main(void)
{

  char s[] = "1234abc";
  printf("s: %s, atoi(s): %d", s, atoi(s));
}

int atoi(char s[])
{
  int n = 0;
  for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}
