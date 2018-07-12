#include <stdio.h>

#define MAXLENGTH 1000


int getline_(char s[]);
int trim(char s[], int n);
void reverse(char s[], int n);

int main(void)
{

  char line[MAXLENGTH];
  int l;
  while((l = getline_(line)) > 0) {
    l = trim(line, l);
    reverse(line, l);
    printf("Trimmed: %s, len: %d \n", line, l);
  }
}


int getline_(char s[])
{
  int i;
  int c;
  for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  return i;
}

int trim(char s[], int n)
{
  int i;
  for (i = n - 1; i >= 0 && (s[i] == '\t' || s[i] == ' '); i--)
    s[i] = '\0';
  return i + 1;
}

void reverse(char s[], int n)
{
  int temp;
  for (int i = 0; i < n - 1 - i; i++) {
    temp = s[i];
    s[i] = s[n - 1 - i];
    s[n - 1 - i] = temp;
  }
}
