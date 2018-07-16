#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000
#define MAXLINES 1000

int getline_(char s[], int m);
int strindex(char source[], char pattern[]);
int strrindex(char[], char[]);

char pattern[] = "pattern";


int main(int argc, char *argv[])
{
  char line[MAXLENGTH];
  char f[MAXLENGTH] = "def";
  long lineno = 0;
  char* match[MAXLINES];
  int n;
  int i = 0;
  int c, except = 0, number = 0, found = 0;
  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        default:
          printf("find: illegal option %c\n", c);
          argc = 0;
          found = -1;
          break;
      }
  if (argc != 1)
    printf("Usage: find.o -x -n pattern\n");
  else {
    while ((n = getline_(line, MAXLENGTH))) {
      lineno++;
      if ((strindex(line, *argv) >= 0) != except )  {
        if (number)
          printf("%ld:", lineno);
        printf("%s", line);
        printf("\n*****\nLast occurence is: %d\n", strrindex(line, *argv));
      }
    }
  }
  return 0;
}

int getline_(char s[], int m)
{
  int i = 0;
  int c;

  while (i < m && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

// return the first occurence of f[] in s[]
int strindex(char s[], char f[])
{
  int j, k;
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; f[k] != '\0' && s[j] == f[k]; j++, k++)
      ;
    if (k > 0 && f[k] == '\0')
      return i;
  }
  return -1;
}
// return the rightmost occurence of f[] in s[]
int strrindex(char s[], char f[])
{
  int  ret = -1;
  int k;
  int i, j;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; f[k] != '\0' && s[j] == f[k]; j++, k++)
      ;
    if (k > 0 && f[k] == '\0')
      ret = i;
  }
  return ret;
}
