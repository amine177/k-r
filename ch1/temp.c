#include <stdio.h>


float fahrenheit_to_celcius(float fahr);


int main()
{
  float fahr = 300;
  printf("%.1f fahrenheit converted to celcius is: %9.1f",
      fahr, fahrenheit_to_celcius(fahr));
}


float fahrenheit_to_celcius(float fahr)
{
  return fahr * 9;
}
