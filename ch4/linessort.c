#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strutils.h"
#include "arrayutils.h"


#define MAXLINES 5000
#define MAXLINECHARS 5000 * 1001

char *lineptr[MAXLINES];

int main(void)
{
  int nbrlines;
  char *linebuf = malloc(MAXLINECHARS);
  nbrlines = readlines(lineptr, MAXLINES, linebuf, MAXLINECHARS);
  qsortutil(lineptr, 0, nbrlines - 1);
  writelines(lineptr, nbrlines);
  return 0;
}
