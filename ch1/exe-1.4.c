#include <stdio.h>

int main(int argc, char *argv[static argc]) {

  printf("-----------------------\n");
  printf("|%10s|%10s|\n", "Celsius", "Fahr");
  for (int cel = 0; cel < 300; cel += 20) {
    printf("|%10d|%10d|\n", cel, ((cel * 9) / 5) + 32);
  }
  printf("-----------------------\n");
  return 0;
}
