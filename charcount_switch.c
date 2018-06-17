#include <stdio.h>


int main(void)
{
  int c, white, other;
  //or just some loop to initialize nbdigit
  int nbdigit[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
                      nbdigit[c - '0']++;
                      break;
      case ' ':
      case '\n':
      case '\t':
                      white++;
                      break;
      default:
                      other++;
                      break;
    }
  }
  printf ("Digits: ");
  for (int i = 0; i < 10; i++)
    // non initialised array have weird values
      printf(" %d", nbdigit[i]);
  printf(", white spaces = %d, other characters = %d\n",
      white, other);
  return 0;
}
