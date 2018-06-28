#include <stdio.h>


#define IN  1
#define OUT  0
int main(void)
{
  int status, nbchar, i;
  int c;
  int histogram[30];

  nbchar = 0;
  i = 0;
  status = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (status == IN) {
        histogram[i++] = nbchar;
      }
      status = OUT;
      nbchar = 0;
    }
    else {
      status = IN;
      nbchar++;
    }
  }
  int j = 0;
  for (; j < i; j++)
    printf("%d ", histogram[j]);
  return 0;
}
