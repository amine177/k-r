#include <unistd.h>
#include <stdio.h>



int getchar(void);
void putchar_(char);

int main()
{
  char c;

  while ((c = getchar()) != EOF)
    putchar_(c);
  return 0;
}


int getchar(void)
{
  static char buf[BUFSIZ];
  static char *bufp;
  static int n = 0;

  if (n == 0) {
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }
  return (--n>= 0) ? (unsigned char) *bufp++ : EOF;
}


void putchar_(char c)
{
  write(1, &c, 1);
}
