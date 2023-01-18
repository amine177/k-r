#include <stdio.h>



int main(int argc, char* argv[static argc]) {


	char c;
	char prev = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			if (prev == ' ') {
				putchar(' ');
				putchar(c);
			} else {
				putchar(c);
			}
		}	

		prev = c;
	}


	return 0;
}
