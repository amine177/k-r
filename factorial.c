#include <stdio.h>


int factorial(int);

int main(void)
{
  int n;
  scanf("%d",&n);
  printf("factorial(%d)=%d", n, factorial(n));
}

int factorial(int n)
{
  if (n != 1)
    n = n * factorial(n - 1);
  return n;
}
