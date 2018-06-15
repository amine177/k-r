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
  return (x >> n) | ((x & ~(~0 << n)) << (l - n));
}
