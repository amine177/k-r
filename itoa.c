#include <stdio.h>
#include <math.h>


void itoa(long n, char s[])
{
  int i = 0;
  int sign = 0;
  char tmp;
  if (n < 0) {
    n = -n;
    sign = 1;
  }
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign)
    s[i++] = '-';
  s[i] = '\0';
  //reverse
  for (int j = 0; j < i / 2; j++) {
    tmp = s[j];
    s[j] = s[i - j - 1];
    s[i - j - 1] = tmp;
  }

}

int main(void)
{
  char s[500];
  itoa(pow(-2, 31), s);
  printf("%s", s);
}
