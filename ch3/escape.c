#include <stdio.h>
#define MAXLENGTH 100

void escape(char[], char[]);

int main(void)
{
  char s[MAXLENGTH];
  char t[4] = {'a', '\n', 'c', '\0'};
  escape(s, t);
  printf("After copying: %s\n", s);
  return 0;
}


void escape(char s[], char t[])
{
  int i = 0;
  int j = 0;
  while (t[i] != '\0') {
    if (t[i] == '\n') {
      s[j++] = '\\';
      s[j++] = 'n';
      i++;
    }
    else if (t[i] == '\t') {
      s[j++] = '\\';
      s[j++] = 't';
      i++;
    }
    else
      s[j++] =  t[i++];
  }
}
