#include <stdio.h>

#define SIZE 100

static char buf[SIZE];
static int bufp = 0;
static int index = 0;
static char* s;

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp < SIZE)
    buf[bufp++] = c;
  else
    printf("error, too many charcters\n");
}
