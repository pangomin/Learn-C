#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y) {
	if ((x & y) >= UINT_MAX) return -1;

	if ((x + y) > UINT_MAX) return -1;
	else return 1;
}

int main(void) {
	if (uadd_ok (-1, -1) == 1) puts("OK");
	else puts("NOK");

	return 0;
}
