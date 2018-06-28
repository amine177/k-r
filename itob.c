#include <stdio.h>


void itob(signed int, char[], int b);


int main(void)
{
  char s[10];
  itob(-110, s, 3);
  printf("%s", s);
}


void itob(signed int n, char s[], int b)
{
  int i, j;
  char tmp;
  int sign = 0;
  if (n < 0) {
    printf("********%d\n", n);
    sign = 1;
    n = -n;
  }
  do {
    if (n % b >= 10)
      s[i++] = 'a' + ( n % b ) - 10;
    else
      s[i++] = '0' + n % b;
  } while ( (n /= b) > 0);
  if (sign)
    s[i++] = '-';
  s[i] = '\0';
  for (j = 0; j < i / 2; j++) {
    tmp = s[j];
    s[j] = s[i - j - 1];
    s[i - j - 1] = tmp;
  }
}
