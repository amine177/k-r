#include <stdio.h>


int htoi(char s[]);
char lower(char);

int main(void)
{
  char s[] = "ax1ff";
  printf("s: %s, htoi(s): %d", s, htoi(s));
}

int htoi(char s[])
{
  int n = 0;
  int i = 0;
  if (s[i] == '0' && lower(s[i+1]) == 'x')
    i += 2;
  for (; s[i] >= '0' && s[i] <= '9'
      || lower(s[i]) >= 'a' && lower(s[i]) <= 'f' ; ++i) {
    if (lower(s[i]) >= 'a' && lower(s[i]) <= 'f')
      n = 16 * n + (10 + lower(s[i]) - 'a');
    else
      n = 16 * n + s[i] - '0';
  }
  return n;
}


char lower(char c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}
