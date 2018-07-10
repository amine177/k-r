#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

void strcatutil(char *s, char *t)
{
  while (*++s)
    ;
  while (*t)
    *s++ = *t++;
  *s = '\0';
}

int strendutil(char *s, char *t)
{
  char *i;
  char *r1, *r2;
  int n, l;

  r1 = s;
  r2 = t;
  n = 0;
  while (*t++)
    n++;
  l = 0;
  while (*s++)
    l++;
  s = r1;
  t = r2;
  for (i = s + l - n; *i = *t; i++, t++)
    if (*i != *t)
      return 0;
  return 1;
}

void strcpyutil(char *s, char *t)
{
  while (*t++ = *s++)
    ;
  *t = '\0';
}

void strncpyutil(char *s, char *t, int n)
{
  char *x = t;
  while ((*t++ = *s++) && --n)
    ;
  
  *t = '\0';
}


void strncatutil(char *s, char *t, int n)
{
  while (*++s)
    ;
  while (*t && n) {
    *s++ = *t++;
    n--;
  }
  *s = '\0';
}

int strncmputil(char *s, char *t, int n)
{
  while( (*s++ == *t++) && --n )
    ;
  if (n != 0)
    return -1;
  return 0;
}

int getline_(char *s, int n)
{
  char c;
  int i;
  i = 0;
  while ((c = getchar()) != EOF && c != '\n' && n--) {
    *s++ = c;
    i++;
  }
  if (c == '\n') {
    *s++ = c;
    i++;
  }
  *s = '\0';
  return i;
}

int readlines(char *lineptr[], int maxlines, char *linesbuf, int size)
{
  int i, len, total, nlines;
  char *p, line[MAXLEN];
  total = 0;
  nlines = 0;
  while ((len = getline_(line, MAXLEN)) > 0)
    if (total > size)
      return -1;
    else {
      if (*(line+len-1) == '\n')
        *(line+--len) = '\0';
      strcpyutil(line, linesbuf+total);
      lineptr[nlines++] = linesbuf+total;
      total =  total + len + 1;
      printf("debug: next : %x\n", linesbuf+total);
    }
  printf("DEBUG: returning %d\n", nlines);
  return nlines;
}

int writelines(char *s[], int n)
{
  int i = 0;
  int j;
  while (i < n) {
      printf("%s\n", s[i++]);
  }
}
