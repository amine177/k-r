#include <stdio.h>



int main(int argc, char* argv[static argc]) {

	int arr[100] = {0};
	char c;
	int lw, maxlw;


	lw = 0;
	maxlw = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (lw > 0) {
				arr[lw]++;
				lw  = 0;
			}
		} else 
			lw++;	

		if (lw > maxlw) {
			maxlw = lw;
		}
	}


	for (int i = 1; i <=  maxlw; i++) {
		if (arr[i])
			printf("arr[%d] = %d\n", i, arr[i]);
	}


	return 0;
}
