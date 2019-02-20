#include <unistd.h>

#define EOF -1

int getchar(void);

int main()
{

  char c;

  while ( (c = getchar()) != EOF)
    write(1, &c, 1);

}



int getchar(void)
{
  char c;

  return read(0, &c, 1) == 1 ? (unsigned char) c : EOF;

}
