#include <stdio.h>

#define swap(t, a, b) \
  t tmp;               \
  tmp = a;              \
  a = b;                 \
  b = tmp;


int main(void)
{
  int x = 2;
  int y = 3;
  swap(int, x, y);
  printf("%d\n", x);
}
