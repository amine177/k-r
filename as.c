#include <stdio.h>


int main(void) {
  char const* sign_repr[4] = {
      "something weird", 
      "sign and magnitude",
      "ones' complement", 
      "two's complement" 
  };

  enum {sign_magic = -1&3};  /* A E S T H E T I C */
  printf("Sign representation used on this computer is %s\n", sign_repr[sign_magic]);
}
