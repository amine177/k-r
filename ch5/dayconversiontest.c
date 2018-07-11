#include <stdio.h>
#include <stdlib.h>
#include "dayconversion.h"

void month_day(int year, int yearday, int *pmonth, int *pda);
int main(void)
{
  int *pm, *pd;
  pm = malloc(2);
  pd = malloc(2);
  printf("the day of year is: %d\n", day_of_year(2012, 3, 15));
  month_day(2012, 75, pm, pd);
  printf("day: %d , month: %d\n", *pd, *pm);
  return 0;
}
