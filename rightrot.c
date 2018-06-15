#include <stdio.h>


unsigned rightrot(unsigned, int, int);

int main(void)
{
  char x = 0x5;
  printf("x: %#x, rightrot(%#x, %d): %#x",
     x, x, 3, rightrot(x, 3, 10));
}


unsigned rightrot(unsigned x, int n, int l)
{
  unsigned y = (x &  ~(~0 << n));
  unsigned z = x >> n;
  return z | (y << (l - n));
}
