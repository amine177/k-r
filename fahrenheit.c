#include <stdio.h>


#define UPPER 300
#define LOWER 0
#define STEP 20
int main(void) {
  float fahr = 0;
  float celcius;

  printf("Fahrenheit | Celcius\n");
  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    printf("%10.0f | %7.1f\n", fahr, (5.0 / 9) * (fahr - 32));
  /*
  for (fahr = UPPER; fahr >= 0; fahr -= 20) {
    celcius = (5.0 / 9) * (fahr - 32);
    printf("%10.0f | %7.1f\n", fahr, celcius);
  }
  */
  /*
  do {
    celcius = 5.0 * (fahr - 32) / 9;
    printf("%-10.0f|%-7.1f\n", fahr, celcius);
    fahr += 20.0;
  } while (fahr <= LIMIT);
  */
  /*
  while (fahr <= LIMIT) {
    celcius = (5. / 9) * (fahr - 32);
    printf("%d\t%d\n", fahr, celcius);
    fahr += 20;
  }
  return 0;
  */
}
