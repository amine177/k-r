#include <stdio.h>


int main(void) {
  int count = 0;
  int c;

  while((c = getchar()) != EOF)
    count++;
  printf("The total number of chars is: %d", count);

  return 0;
}
