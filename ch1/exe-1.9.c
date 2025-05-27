#include <stdio.h>



int main(int argc, char* argv[static argc]) {

  char prev = 'a';
  char c;

  while((c = getchar())!=EOF) {

    if (((c == ' ' || c == '\t')
	 && (prev != ' ' && prev != '\t'))
	|| (c != ' ' && c != '\t')) {
      putchar(c);
    }

    prev = c;
  }

  return 0; 
}
