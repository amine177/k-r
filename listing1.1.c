#include <stdio.h>

int main(void)
{
  int dogs;

  printf("How many dogs do you have?\n");
  scanf("%d", &dogs);
  printf("So you have %d dogs(s)!\n", dogs);

  return 0;
}
