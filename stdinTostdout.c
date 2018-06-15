#include <stdio.h>


int main(void)
{
  int c;

  c = getchar();
  printf("%d\n", EOF);
  while (c != EOF) {
    putchar(c);
    c = getchar();
    if (c == EOF)
      putchar('X');
  }
}
