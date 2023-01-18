#include <stdio.h>


int main(int argc, char* argv[static argc]) {

	printf("Celsius\tFahr\n");
	for (int cel = 0; cel < 300; cel += 20) {
		printf("%d\t%d\n", cel,  ((cel * 9) / 5 ) + 32);
	}

	return 0;
}
