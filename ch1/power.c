#include <stdio.h>

int power(int, int);

int main(void)
{
  int i;
  for (i = 0; i < 10; ++i)
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
}

int power(int base, int n)
{
  if (n == 0)
    return 1;
  else if (n == 1)
    return base;
  else
    return base * power(base, n - 1);
}
