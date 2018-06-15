#include <stdio.h>


char lower(char c);

int main(void)
{
  char c;
  printf("Enter a character:\n");
  c = getchar();
  printf("c: %c, lower(c): %c", c, lower(c));
}

char lower(char c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}
