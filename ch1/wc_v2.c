#include <stdio.h>

int wcount = 0;
int lcount = 0;
int ccount = 0;

int is_alphanum(char c) {
  return (c != ' '  &&
	  c != '\t' &&
	  c != '\n');
 }

int is_word(char c) {
  return is_alphanum(c);
}

void count_char_and_newline(char c) {
  ccount++;
  if (c == '\n')
    lcount++;
}

int new_word() {
  int c;

  while ((c = getchar()) != EOF)
    {
      if (is_word(c)) {
	  wcount++;
	  break;
	}
      count_char_and_newline(c);
		  
    }

  for (; c != EOF; c = getchar())
    {
      count_char_and_newline(c);
      if (!is_word(c))
	break;
      
    }

  return c != EOF;
}


void counter() {
  ccount = wcount = lcount = 0;
  while (new_word())
    ;
  printf(" ccount: %d, wcount: %d, lcount: %d\n", ccount,
	 wcount, lcount);
    
}

int main(int argc, char* argv[static argc]) {
  counter();
}
