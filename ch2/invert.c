#include <stdio.h>


unsigned invert(unsigned, int, int);

int main(void)
{
  int c = getchar();
  int n = 4;
  int p = 5;
  getchar();
  printf("c: %#x, invert(%x, %d, %d) : %#x",
      c, c, p, n, invert(c, p, n));
}

unsigned invert(unsigned x, int p, int n)
{
  //or just call getbits and setbits
  unsigned y = ~((x >> (p+1-n)) & ~(~0 << n));
  return (x & ~(~(~0 << n) << (p+1-n))) | ((y & ~(~0 << n)) << (p+1-n));

}
