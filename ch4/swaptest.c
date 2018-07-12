#include <stdio.h>
#include "swap.h"


int main(void)
{
  int a, b;
  int *pa, *pb;
  a = 5;
  b = 10;
  pa = &a;
  pb = &b;
  swap(pa, pb);
  printf("a: %d, b: %d\n", *pa, *pb);
  return 0;
}
