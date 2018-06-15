#include <stdio.h>


void squeeze(char[], char[]);

int main(void)
{
  char s1[] = "abcdaminfft";
  char s2[] = "amint";
  printf("s1: %s\n", s1);
  squeeze(s1, s2);
  printf("sequeeze(s1, s2): %s\n", s1);
}


void squeeze(char s1[], char s2[])
{
  int k = 0;
  int i, j;
  while (s2[k] != '\0') {
    for (i = j = 0; s1[i] != '\0'; ++i)
      if (s1[i] != s2[k])
        s1[j++] = s1[i];
    s1[j] = '\0';
    k++;
  }
}
