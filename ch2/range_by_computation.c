#include <limits.h>
#include <float.h>
#include <stdio.h>


int main()
{
  int i;
  int n;
  unsigned int ui;
  float f;
  short s;
  unsigned short us;
  double d;
  long l;
  unsigned long ul;
  long int li;
  long long ll;

  printf("Limits from headers:\n");
  printf("char: %d, %d\n", CHAR_MIN, CHAR_MAX);
  printf("signed char: %d, %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char: max: %d\n", UCHAR_MAX);
  printf("short: %d, %d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short: max: %d\n", USHRT_MAX);
  printf("int: %d, %d\n", INT_MIN, INT_MAX);
  printf("signed int: %d, %d\n", INT_MIN, INT_MAX);
  printf("unsigned int: max: %ud\n", UINT_MAX);
  printf("float: %f, %f\n", FLT_MIN, FLT_MAX);
  printf("[signed] long long: %lld, %lld\n", LLONG_MIN, LLONG_MAX);
  printf("unsigned long long: max: %llu\n", ULLONG_MAX);

 // TODO: computation

  i = 1;
  n = 0;
  char c;
  while (n < i) {
    while (i + i - n   > i)
      i = i + i - n;
    n++;
  }

  printf("Maximum integer: %d\n", i);
  i = -1;
  n = 0;
  while (n < -i) {
    while (i + i + n   < i)
      i = i + i + n;
    n++;
  }
  printf("Minimum integer: %d\n", i);

  ui = 0;

  while (ui + ui > ui)
    ui += ui;

  printf("Maximum unsigned integer: %d\n", ui);

  return 0;
}
