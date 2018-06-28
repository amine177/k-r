#include <stdio.h>


unsigned setbits(unsigned, int, unsigned, int);

int main(void)
{
  int c = getchar();
  int n = 4;
  int p = 3;
  getchar();
  char b = getchar();
  printf("c: %#x, b: %#x, setbits(%x, %d, %x, %d): %#x",
      c, b, c, p, b, n, setbits(c, p, b, n)
      );
}


unsigned setbits(unsigned x, int p, unsigned y, int n)
{
  return (x & ~(~(~0 << n) << (p+1-n))) | ((y & ~(~0 << n)) << (p+1-n));
}
