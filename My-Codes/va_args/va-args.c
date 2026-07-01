#include <stdarg.h>
#include <stdio.h>

/*
 * Computes the sum of a variable number of integer arguments.
 *
 * Parameters:
 *   count	Number of integer arguments that follow.
 *   ...    The integer values to be summed.
 *
 * Returns:
 *   The sum of all supplied integers.
 */

int sum(int count, ...) {
	int total = 0;
	va_list ap;
	va_start(ap, count);

	for(int i = 0; i < count; i++) {
		total+= va_arg(ap, int);
	}
	va_end(ap);

	return total;

}

#define SQUARE(T, x) ((T)((x) * (x)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
	printf("%d\n", SQUARE(int, 2));
	printf("%d\n", MAX(1, 1));

	printf("%d\n", sum(2, 20, 30));
	return 0;
}
