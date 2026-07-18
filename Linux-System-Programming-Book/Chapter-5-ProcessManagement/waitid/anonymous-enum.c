#include <stdio.h>

int main(void) {
	enum
	{
		A = 20,
		B = 30,
		C = 40
	};
	printf("A: %d\nB: %d\nC: %d\n", A, B, C);
}
