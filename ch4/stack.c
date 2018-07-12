#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void push(double f)
{
  if (sp < MAXVAL) {
    val[sp++] = f;
  }
  else
    printf("error: stack full, can't push %g\n", f);
}


double pop(void)
{
  if (sp > 0) {
    return val[--sp];
  }
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

double peek(void)
{
  if (sp > 0)
    return val[sp - 1];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void swap(void)
{
  double tmp;
  if (sp > 1) {
    tmp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = tmp;
    printf("swap done\n");
  }
  else
    printf("error: stack doesn't have tow elements\n");
}

void clear(void)
{
  sp = 0;
}
