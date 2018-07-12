#include <stdio.h>


unsigned getbits(unsigned x, int p, int n);

int main(void)
{
  int c = getchar();
  printf("c: %#x\ngetbits(%c, %d, %d): %x", c, c, 3, 4, getbits(c, 3, 4));
}


unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}
