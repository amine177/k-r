#include <stdio.h>



int main(int argc, char* argv[static argc]) {

	char c;

	int arr[42] = {0};


	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			if (c >= 'a' && c <= 'z')
				arr[c - 'a']++;
			else if (c >= 'A' && c <= 'Z')
				arr[26 + ('A' - c)]++;
		}
	}


	for (int i = 0; i < 26; i++) {
		printf("%c : %d, ", i + 'a', arr[i]);
	}
	for (int i = 26; i < 42; i++) {
		printf("%c : %d, ", (i - 26) + 'A', arr[i]);
	}


	return 0;
}
