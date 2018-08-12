#include <stdio.h>
#include <ctype.h>


#define MAXLINE 10

int main()
{
  int c, cn;

  cn = 0;
  while ((c = getchar())!= EOF) {
    if (cn++ == MAXLINE) {
      printf("\n");
      cn = 0;
    }
    if (isascii(c))
      printf("%c", c);
    else
      printf("%x", c);
  }

  return 0;
}
