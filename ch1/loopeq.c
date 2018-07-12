#include <stdio.h>
#define lim 10

int main(void)
{
  char s[lim];
  int i;
  int c;


  for (i = 0; i < lim -1; ++i) {
    c = getchar();
    if (c == EOF)
      break;
    if (c == '\n')
      break;
    s[i] = c;
  }

  printf("%s", s);
}
