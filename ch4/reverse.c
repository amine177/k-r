#include <stdio.h>

void reverse(char[], int, int);
int main(void)
{
  char v[] = "abc";
  reverse(v, 0, 2);
  printf("%s\n", v);
  return 0;
}

void reverse(char s[], int left, int right)
{
  int tmp;
  if (left >= right)
    return;
  tmp = s[left];
  s[left] = s[right];
  s[right]= tmp;
  reverse(s, ++left, --right);
}
