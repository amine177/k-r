#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLENGTH 1000

int replacetabs(char s[], int l, int n, int i, char c);
int getline_(char s[]);


int main(int argc, char *argv[])
{
  char s[MAXLENGTH];
  int n = 3;
  int i = 0;
  int l, c = '*';

  while (argc-- > 1) {
    switch ((*++argv)[0]) {
      case '-':
        if (isdigit((*argv)[1]))
          i = atoi(&((*argv)[1]));
        break;
      case '+':
        if (isdigit((*argv)[1])) {
          n = atoi(&((*argv)[1]));
        }
        break;
      default:
        c = *argv[0];
        break;
    }
  }
  while ((l = getline_(s)) > 0) { 
    l = replacetabs(s, l, n, i, c);
    printf("Line %d,%ds/\\t/%dspaces: %s\n", i, l - 1, n, s);
  }
}


int getline_(char s[])
{
  int c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int replacetabs(char s[], int l, int n, int index, char c)
{
  int i = 0;
  if (l + n > MAXLENGTH)
    return -1;
  while (s[i] != '\0') {
    if (s[i] == '\t' && i >= index) {
      for (int j = l + n - 1; j > i + n - 1; j--)
        s[j] = s[j - n + 1];
      for (int j = 0; j < n; ++j)
        s[i + j] = c;
      i += n - 1;
      l += n - 1;
    }
    else
      i++;
  }
  return i;
}
