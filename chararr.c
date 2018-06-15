#include <stdio.h>


int main(void)
{
  char s[3];
  char c;
  c = getchar();
  s[0] = c;
  printf("\n%c", *s);
  return 0;
}
