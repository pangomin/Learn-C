#include <stdio.h>

int main(void) {
	int x = -6;
	unsigned px = (unsigned) x;

	printf("x: %d px: %u\n", x, px);

	printf("long: %lu, uint: %u\n", (unsigned long)-1, (unsigned)-1);

	return 0;
}
