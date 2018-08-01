#include <stdio.h>
#include "bufutilsparser.h"
#include <ctype.h>
#include <string.h>


#define MAXWORD 100


int getvar(char*, int);

int main(int argc, char **argv)
{
  char s[MAXWORD];
  while (getvar(s, MAXWORD) != EOF)
    printf("var: %s\n");
}


int getvar(char *s, int n)
{

  int getword(char *, int);
  while (getword(s, n) != EOF)
    if (strcmp(s, "int") == 0 || strcmp(s, "float") == 0) {
      while (getword(s, n) != EOF && strcmp(s, "*") == 0)
        ;
      getword(s, n);
      return s[0];
    }
  return EOF;
}

int getword(char *s, int n)
{
  int c, i = 0;
  while (isspace(c = getch()))
    ;

  if (c != EOF && n-- > 0)
    s[i++] = c;
  if (!isalpha(c) && c != '_' && c != '-' && n-- > 0 ) {
    s[i] = '\0';
    if (c == EOF)
      return c;
    else
      return i;
  }

  while((isalnum(c = getch()) || c == '_' || c == '-') && n-- > 0)
    s[i++] = c;
  if (!isalpha(c))
    ungetch(c);
  s[i] = '\0';

  return i;
}
