#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000
#define MAXLINES 1000

int getline_(char s[], int m);
int strindex(char source[], char pattern[]);
int strrindex(char[], char[]);

char pattern[] = "pattern";


int main(void)
{
  char line[MAXLENGTH] = "abcdefgh";
  char f[MAXLENGTH] = "def";
  char* match[MAXLINES];
  int n;
  int i = 0;
  char *c;
  while ((n = getline_(line, MAXLENGTH)))
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      printf("\n*****\nLast occurence is: %d\n", strrindex(line, pattern));
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
