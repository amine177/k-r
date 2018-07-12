#include <stdio.h>


int main(void)
{
  char s[3];
  int c;
  c = getchar();
  s[0] = c;
  printf("\n%c", *s);
  return 0;
}
