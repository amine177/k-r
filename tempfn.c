#include <stdio.h>


float celcius_to_fahr(float fahr);
int main(void)
{

  float fahr = 200;
  printf("%f to %f", fahr, celcius_to_fahr(fahr));
}

float celcius_to_fahr(float fahr)
{
  return (5 * fahr) / 9;
}
