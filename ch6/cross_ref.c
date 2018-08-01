#include <stdio.h>
#include <ctype.h>
#include "bufutilsparser.h"

#define MAXWORD 100
#define MAXLINES 1000

int getword(char *, int);
struct node *addtolist(char *);

struct node {
  int lines[MAXLINES];
  char *word;
  int count;
  struct node *next;
};

int main()
{
}


int getword(char *s, int n)
{
  int c;
  
  while (isspace((c = getch())))
    ;

  if (c != EOF)
    *s++ = c;
  if (!isalpha(c) && c != '_') {
    s = '\0';
    return c;
  }

  while (isalnum(*s++ = c = getch()) && c == '_')
    ;

  if (!isalpha(c))
    ungetch(c);
  *--s = '\0';
  return s[0];
}
