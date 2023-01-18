#include <stdio.h>

/*
 * exe-1.2.c: In function ‘main’:
 * exe-1.2.c:5:9: warning: unknown escape sequence: '\c'
 * 5 |  printf("testing \c\n");
 *   |         ^~~~~~~~~~~~~~
 */


int main(int argc, char* argv[static argc]) {
	printf("testing \c\n");
	return 0;
}
