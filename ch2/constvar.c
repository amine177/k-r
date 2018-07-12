#include <stdio.h>

int fn(const int i);
int main(void)
{
  const int i = 5;
  i = 5;
}

int fn(const int i)
{
  i = 5;
  return i;
}
