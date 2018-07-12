#include <stdio.h>


int main(void)
{
  int c, nl;
  int spacec;

  nl = 0;
  spacec = 0;
  while ((c = getchar()) != EOF) {
    if (c == 9)
      c = '\t';
    if ( c == ' ')
      spacec += 1;
    if (spacec != 2) {
      printf("%c", c);
    }
    else
      spacec = 0;
    if ( c == '\n')
      nl++;
  }
  printf("%d\n", nl);
}
