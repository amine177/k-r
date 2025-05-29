#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
  int nl, nw, nc, state;
  char c;

  nl = nw = nc = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    nc++;
    if (c != ' ' && c != '\n' && c != '\t') {
      //printf("%c", c);
      if (state == OUT)
        state = IN;
    } else {
      if (state == IN) {
        //printf("\n");
        state = OUT;
        nw++;
      }
      if (c == '\n')
        nl++;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}
