#include "minprintf.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXDECIMAL 4

int main(int argc, char *argv[])
{
  minprintf("%-3.2f, %3d, %3.2s\n", 5.2, 2, "ab");
  return 0;
}


void minprintf(char *fmt, ...)
{
  va_list ap;
  char *p, *sval, *decstr = (char *) malloc(MAXDECIMAL);
  char *precstr = (char *) malloc(MAXDECIMAL), *format;
  int ival, decimal, precision, length, width, minus, fmtlen, i;
  double dval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    fmtlen = 0;

    precision = 0;
    width = 0;
    minus = 0;

    if (*++p == '-')
      minus = 1;
    else
      --p;
    length = 0;
    i = 0;
    while(isdigit(*++p))
      if (length < MAXDECIMAL)
        decstr[i++] = *p;
    decstr[i] = '\0';

    i = 0;
    if (*p == '.') {
      length = 0;
      while (isdigit(*++p))
        if (++length < MAXDECIMAL)
          precstr[i++] = *p;
      precstr[i] = '\0';
      --p;
    } else --p;

    if (minus)
      fmtlen++;
    if (strlen(decstr))
      fmtlen +=  strlen(decstr);
    if (strlen(precstr))
      fmtlen += strlen(precstr);
    format = (char *) malloc(fmtlen+2);
    strcat(format, "%");
    if (minus)
      strcat(format, "-");
    if (*decstr)
      strcat(format, decstr);
    if (*precstr) {
      strcat(format, ".");
      strcat(format, precstr);
    }

    switch(*++p) {
      case 'd':
        ival = va_arg(ap, int);
        strcat(format, "d");
        printf(format, ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        strcat(format, "f");
        printf(format, dval);
        break;
      case 's':
        decimal = atoi(decstr);
        precision = atoi(precstr);
        if (minus) {
          for (sval = va_arg(ap, char*); *sval && --precision; sval++, decimal--)
            putchar(*sval);
        }
        else {
          sval = va_arg(ap, char*);
          while(decimal-- > strlen(sval))
            putchar(' ');
          for (; *sval && precision--; sval++)
            putchar(*sval);
        }
        break;
      default:
        putchar(*p);
        break;
    }
  }
}
