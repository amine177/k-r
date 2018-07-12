#include <stdio.h>

int main(void) {

  unsigned char ch =  'a';
  unsigned char* add = 0x0;;

  printf("ch address is %d\n", &ch);
  printf("ch address is %x\n", &ch);
  printf("Enter the adress in which you want to put value: ");
  scanf("%p", add);
  printf("Please enter a character:\n");
  scanf("%c", &ch);

  printf("The char in int form is %d, the char in char form is %c\n", ch, ch);
  printf("The value of *add is %c", *add);
  printf("D is %x", add);

  return 0;
}
