#include <stdio.h>

#define MAXLENGTH 100


void escape(char[], char[]);

int main(void)
{
  char s[MAXLENGTH];
  char t[5] = {'a', '\n', '\t', 'b', '\0'};
  escape(s, t);
  printf("After copying: %s\n", s);
}

void escape(char s[], char t[])
{
  int i = 0;
  int j = 0;


  while (t[i] != '\0') {
    switch (t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        i++;
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        i++;
        break;
      default:
        s[j++] = t[i++];
        break;
    }
  }
}
