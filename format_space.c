#include <stdio.h>


int main(void)
{
  float x = 520.3;

  printf("X is %6.3f", x);
  printf("Delimiter reached!\n");
  scanf("%f", &x);

  char c;
  c = getchar();
  printf("a");
  printf("%c", c);
  printf("a");

  return 0;
}
