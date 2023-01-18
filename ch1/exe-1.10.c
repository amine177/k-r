#include <stdio.h>


int main(int argc, char* argv[static argc]) {


	char c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\n') {
			putchar('\\');
			putchar('n');
		} else if (c == '\\') {
			putchar('\\');
		} else {
			putchar(c);
		}

	}

	return 0;
}
