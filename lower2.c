#include <stdio.h>


char lower(char);

int main(void)
{
  int c = getchar();
  printf("c: %c, lower(%c): %c", c , c , lower(c));
  return 0;
}

char lower(char c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
