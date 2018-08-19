#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

#define MAXPRECISION 1000
#define MAXWIDTH 1000
#define DEFAULT_WIDTH -1
#define DEFAULT_PREC -1
#define DEFAULT_MINUS -1
#define MAXINT 20 

static void _itoa(long n, char s[])
{
  int i = 0;
  int sign = 0;
  char tmp;
  if (n < 0) {
    n = -n;
    sign = 1;
  }
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign)
    s[i++] = '-';
  s[i] = '\0';
  //reverse
  for (int j = 0; j < i / 2; j++) {
    tmp = s[j];
    s[j] = s[i - j - 1];
    s[i - j - 1] = tmp;
  }

}

void realprintf(char *fmt, ...)
{

  int precision, width, minus, ival, i;
  va_list ap;
  char *p, *sval, itoa[MAXINT];

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    minus = DEFAULT_MINUS;
    precision = DEFAULT_PREC;
    width = DEFAULT_WIDTH;
    if (*++p == '-')
      minus = 1;
    else p--;
    if (isdigit(*++p)) {
      width = 0;
      for (; isdigit(*p); p++)
        width = 10 * width + (*p - '0');
      p--;
    }
    else p--;
    if (*++p == '.')
      if (*++p == '*')
        precision = va_arg(ap, int);
      else if (isdigit(*p)) {
        precision = 0;
        for (; isdigit(*p); p++)
          precision = 10 * precision + (*p - '0');
        p--;
      }
      else p--;
    else p--;
    switch (*++p) {
      case 'd':
        goto print_number;
        break;
      case 's':
        goto print_string;
        break;
      default:
        putchar(*p);
        break;
    }
loop:
    ;
  }

  va_end(ap);
  return;


print_number:
  i = 0;
  ival = va_arg(ap, int);
  _itoa(ival, itoa);
  sval = itoa;
  width -= strlen(itoa);
  precision -= strlen(itoa);
  if (minus == DEFAULT_MINUS)
    while (width-- > 0)
      putchar(' ');
  while (precision--  > 0)
    putchar('0');
  while (*sval)
    putchar(*sval++);
  if (minus != DEFAULT_MINUS)
    while (width-- > 0)
      putchar(' ');
  goto loop;
print_string:
  sval = va_arg(ap, char *);
  width -= (strlen(sval) - precision != DEFAULT_MINUS ? precision: 0);
  if (minus == DEFAULT_MINUS)
    while (width-- > 0)
      putchar(' ');
  if (precision != DEFAULT_MINUS)
    while (*sval && precision-- > 0)
      putchar(*sval++);
  else
    while (*sval)
      putchar(*sval++);
  if (minus != DEFAULT_MINUS)
    while (width-- > 0)
      putchar(' ');
  goto loop;
}

int main(int argc, char *argv[])
{
  realprintf("%-3di am\n here, number:%3.2d\n", 3, 1);
  realprintf("%-13.3sso\n", "i am here");
}
