#include <stdio.h>

int main(void) {
  
  printf ("audible alert (bell) BEL \\a %d\n", '\a');
  printf("backspace             BS \\b %d\n", '\b');
  printf("horizontal tab        HT \\t %d\n", '\t');
  printf("newline               LF \\n %d\n", '\n');
  printf("vertical tab          VT \\v %d\n", '\v');
  printf("formfeed              FF \f a %d\n", '\f');
  printf("carriage return       CR \\r %d\n", '\r');

  return 0;
}
