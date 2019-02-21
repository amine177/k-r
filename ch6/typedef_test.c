#include <stdio.h>
#include <stdlib.h>

typedef char *String;

int main(void)
{
  String s;

  s = (String) malloc(sizeof(String) * 3);
  s = "ab\0";


  return 0;
}
