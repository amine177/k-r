#include <stdio.h>


int main()
{
  enum months { JAN = 1, FEB, JUL = 2 };

  printf("JAN: %d\n", JAN);
  printf("FEB: %d\n", FEB);
  printf("JUL: %d\n", JUL);

  return 0;
}
