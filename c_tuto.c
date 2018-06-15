#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(void) {

  int a[2];

  int j = 0;
  a[j] = j++;

  printf("a[0] is %d, a[1] is %d", a[0], a[1]);
  return 0;
}
