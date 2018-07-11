#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
  int i, leap;
  
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pda)
{
  int leap, i;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pda = yearday;
}

int day_of_yearp(int year, int month, int day)
{
  int leap;
  char *p;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (p = &daytab[leap][1]; *p < month; p++)
    day += *p;
  return day;
}

void month_dayp(int year, int yearday, int *pmonth, int *pda)
{
  int leap;
  char *p;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  p = &daytab[leap][1];
  for (; yearday > *p; p++)
    yearday -= *p;
  *pmonth = &daytab[leap][1] - p + 1;
  *pda = yearday;
}
