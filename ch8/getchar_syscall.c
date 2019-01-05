#include <unistd.h>
#include <stdio.h>


int getchar_(void);
void putchar_(char);


int main()
{
  char c;

  while  ((c = getchar_()) != EOF)
    putchar_(c);
}


int getchar_(void)
{
  char c;

  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

void putchar_(char c)
{
  write(1, &c, 1);
}
