#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
  int c, nl, nw, nc, state;
  int print;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if ( c == ' ' || c == '\n' || c == '\t' && state != OUT)
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
    if (state == IN && c != ' ' && c != '\n' && c != '\t') {
      printf("%c", c);
      print = OUT;
    }
    else if (print == OUT) {
      printf("\n");
      print = IN;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}
