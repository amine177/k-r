#include <stdio.h>


int main(int argc, char* argv[static argc]) {

	for (int fahr = 300; fahr >= 0; fahr -= 20) {
		printf("%d\t%d\n", fahr, 5 * (fahr - 32) / 9);
	}

	return 0;
}
