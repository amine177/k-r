#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "bufutilsparser.h"

#define MAXWORD 100
#define NKEYS 11

struct key {
  char *word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "case", 0,
  "char", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(void)
{
  int n;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if ((n = binsearch(word, keytab, NKEYS)) >= 0)
        (&keytab[n])->count++;

  for (int i = 0; i < NKEYS; i++)
    printf("%s:%d\n", keytab[i].word, keytab[i].count);
  return 0;
}


int binsearch(char *word, struct key tab[], int n)
{
  int low = 0, high = n - 1, mid, cond;
  while (low <= high) {
    mid = (low+high) / 2;
    if ((cond = strcmp(word, tab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

int getword(char *s, int n)
{
  int c, getch(void);
  void ungetch(int);
  char *w = s;

  while (isspace(c = getch()))
    ;

  if (c != EOF)
    *w++ = c;
  if (!isalpha(c) && c != '_') {
    *w = '\0';
    return c;
  }

  for (; --n > 0; w++)
    if (!isalnum(*w = getch()) && *w != '_') {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return s[0];
}
