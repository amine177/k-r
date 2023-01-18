#include <stdio.h>



int main(int argc, char* argv[static argc]) {
	char c;
	char prev = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (prev != ' ' && prev != '\t' && prev != '\n') {
				putchar('\n');
			}
		} else {
			putchar(c);
		}

		prev = c;
	}
	return 0;
}
