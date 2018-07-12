#include <stdio.h>


int main(void)
{
  char c;
  int i;
  float f;
  double d;
  long l;
  long int li;
  long long int lli;
  long double ld;
  short int si;

  printf("Sized are bytes:\n" \
      "char: %d, int: %d, float: %d, double: %d" \
      " long int: %d, long long int: %d"\
      " short int : %d, long double: %d", \
      sizeof(c), sizeof(i), sizeof(f), sizeof(d),
      sizeof(li), sizeof(lli), sizeof(si), sizeof(ld));
}
