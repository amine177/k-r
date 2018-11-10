#include <stdio.h>


int main()
{
  char s[] = "abc";
  int strlen_impl(char[]);

  printf("len: %d\n", strlen_impl(s));

  return 0;
}


int strlen_impl(char s[])
{
  int i;

  i = 0;
  while (s[i++])
    ;

  return --i;
}
