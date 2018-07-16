#include <ctype.h>
#include <stdio.h>
#include "stack.h"
#include "bufutils.h"
#define NUMBER 1
static int index = 1;
char getop(char s[], char *src[], int n)
{
  int c;
  int i;
  if (index == n)
    return EOF;
  while ((s[0] = c = getch(src[index])) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    index++;
    return c;
  }
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch(src[index])))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch(src[index])))
      ;
  if (c != EOF && c != '\0') {
    ungetch(c);
  }
  index++;
  s[i] = '\0';
  return NUMBER;
}
