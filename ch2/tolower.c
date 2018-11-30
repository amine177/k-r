#include <stdio.h>

void tolower_(char s[]);

int main()
{
  char s[] = "AbC";

  tolower_(s);
  printf("%s\n", s);
}

void tolower_(char s[])
{
  int i;

  for (i = 0; s[i] != '\0'; i++)
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] = s[i] + 'a' - 'A';
}
