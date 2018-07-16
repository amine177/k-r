#include <stdio.h>

#define SIZE 100

static char buf[SIZE];
static int bufp = 0;
static int index = 0;
static char* s;

int getch(char *src)
{
  if (!index)
    s = src;
  if (s != src) {
    index = 0;
    s = src;
  }
    return (bufp > 0) ? buf[--bufp] : *(src+index++);
}

void ungetch(int c)
{
  if (bufp < SIZE)
    buf[bufp++] = c;
  else
    printf("error, too many charcters\n");
}
