#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>


#define DEFAULT_MINUS -1
#define DEFAULT_PRECISION -1
#define DEFAULT_WIDTH -1

int realscanf(char *fmt, ...)
{
  int read;
  char c;
  char *p;
  va_list ap;

  read = 0;
  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      goto read_chars;
loop:
      ;
    }

    switch (*++p) {
     default:
       printf("ok");
    }
  }
read_chars:
  while (*p && *p != '%' && *p == (c =  getchar()) && c != EOF) {
    printf("*%c\n", *p);
    read++;
    p++;
  }
  if (*p != '%')
    return read;
  goto loop;
}

int main(int arg, char *argv[])
{
  int n;
  realscanf("hello%d\n", n);
  return 0;
}
