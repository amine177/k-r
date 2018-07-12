#include <stdio.h>
#include <limits.h>


int main(void)
{

  printf("Limit char min: %d\n", CHAR_MIN);
  printf("Limit char max: %d\n", CHAR_MAX);

  printf("Limit int min: %d\n", INT_MIN);
  printf("Limit int max: %d\n", INT_MAX);

  printf("Limit short min: %d\n", SHRT_MIN);
  printf("Limit short max: %d\n", SHRT_MAX);

  char c =0;
  while (c + 1 > c++)
    ;
  c -= 1;
  printf("Max char: %d\n", c);
  c = 0;
  while (c - 1 < c--)
    ;
  c += 1;
  printf("Min char: %d\n", c);

  int x = 0;
  while (x + 1 > x++)
    ;
  x -= 1;
  printf("Max int: %d\n", x);
  x = 0;
  while (x - 1 < x--)
    ;
  x += 1;
  printf("Min int: %d\n", x);

  return 0;
}
