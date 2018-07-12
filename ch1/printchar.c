#include <stdio.h>


int main(void) {
  int c;

  printf("EOF: %x\n", EOF);
  while ((c = getchar()) != EOF ) {
    putchar(c);
  }
  return 0;
}
