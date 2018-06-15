#include <stdio.h>

int main(void)
{

  int fathoms;
  int feet;

  printf("Enter an amount of fathoms:\n");
  scanf("%d", &fathoms);
  feet = fathoms * 6;

  printf("Your conversion is %d", feet);
}
