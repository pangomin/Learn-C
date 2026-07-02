#include <stdarg.h>
#include <stdio.h>

/*
 * Computes the sum and maximum of a variable number of integer arguments
 * and prints the result.
 *
 * Parameters:
 *   count	Number of integer arguments that follow.
 *   ...    The integer values to be summed.
 */

void sum(int count, ...) {
	int total = 0;
	int value;
	int max;

	va_list ap;
	va_start(ap, count);
	if (count <= 0) {
		va_end(ap);
		fprintf(stderr, "No arguments passed!\n");
		return;
	}

	value = va_arg(ap, int);
	max = value;
	total += value;
	for(int i = 0; i < count - 1; i++) {
		value = va_arg(ap, int);
		total += value;
		if(value > max) {
			max = value;
		}
	}
	va_end(ap);
	printf("Total = %d\n", total);
	printf("Greatest number = %d\n", max);
}
// Macro to see the logic of stdarg
#define SQUARE(T, x) ((T)((x) * (x)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
	printf("%d\n", SQUARE(int, 2));
	printf("%d\n", MAX(1, 1));

	sum(5, -1, -2, -3, 0, 2);
	return 0;
}
