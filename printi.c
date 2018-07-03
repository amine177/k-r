#include <stdio.h>


void printi(int n);

int main(void)
{

  int n = 500;
  printi(500);
  return 0;
}


void printi(int n)
{
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10)
    printi(n / 10);
  putchar(n % 10 + '0');
}
