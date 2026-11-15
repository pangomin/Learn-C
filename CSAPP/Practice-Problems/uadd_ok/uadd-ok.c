#include <stdio.h>

int uadd_ok(unsigned x, unsigned y) {
	if (((x + y) / 32) < (x || y))
		return 0;

	return -1;
}

int main(void) {
	if (uadd_ok (-1, -1) == 0)
		puts("OK");
	else
		puts("NOK");

	return 0;
}
