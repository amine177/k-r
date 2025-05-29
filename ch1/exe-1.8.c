#include <stdio.h>

int main(int argc, char *argv[static argc]) {

  char c;
  int blanks, tabs, newlines;
  blanks = tabs = newlines = 0;
  while ((c = getchar()) != EOF) {
    tabs += (c == '\t');
    newlines += (c == '\n');
    blanks += (c == ' ');
  }

  printf("tabs: %d, newlines: %d, tabs: %d\n",
         tabs, newlines, blanks);

  return 0;
}
