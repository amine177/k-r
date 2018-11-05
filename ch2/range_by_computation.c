#include <limits.h>
#include <float.h>
#include <stdio.h>


int main()
{
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

  return 0;
}
