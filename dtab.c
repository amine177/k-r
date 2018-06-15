#include <stdio.h>

#define MAXLENGTH 1000

int replacetabs(char s[], int l, int n);
int getline_(char s[]);


int main(void)
{
  char s[MAXLENGTH];
  int n = 3;
  int l;
  while ((l = getline_(s)) > 0) { 
    l = replacetabs(s, l, n);
    printf("Line s/tab/%dspaces: %s\n", n, s);
  }
}


int getline_(char s[])
{
  char c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int replacetabs(char s[], int l, int n)
{
  int i = 0;
  if (l + n > MAXLENGTH)
    return -1;
  while (s[i] != '\0') {
    if (s[i] == '\t') {
      for (int j = l + n - 1; j > i + n - 1; j--)
        s[j] = s[j - n + 1];
      for (int j = 0; j < n; ++j)
        s[i + j] = '*';
      i += n - 1;
      l += n - 1;
    }
    else
      i++;
  }
  return i;
}
