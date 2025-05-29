#include <stdio.h>


int main(int argc, char* argv[static argc]) {

  printf("-----------------------\n");
  printf("|%10s|%10s|\n", "Fahr", "Celsius");
  for (int fahr = 300; fahr > 0; fahr -= 20) {
    printf("-----------------------\n");
    printf("|%10d|%10d|\n", fahr, 5 * (fahr - 32) / 9);
  }
  printf("-----------------------\n");

  return 0;
}
