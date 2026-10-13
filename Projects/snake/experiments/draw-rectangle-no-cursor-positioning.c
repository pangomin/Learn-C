#include <stdio.h>

int
main(void) {
	int w, h, a, b;
	h = 4;
	w = 4;

	for (a = 0; a != 4; a++) {
		for (b = 0; b != 4; b++) {
			if (a == 0 || b == 0 || b == 3 || a == 3)
				printf("*");
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
