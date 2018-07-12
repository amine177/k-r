#include <stdio.h>
#include "alloc.h"

int main(void)
{
  char *p = alloc(8);
  printf("p: %x\n", p);
  afree(p);
  p = alloc(8);
  printf("p: %x\n", p);
  p = alloc(8);
  printf("p: %x\n", p);
  return 0;
}
