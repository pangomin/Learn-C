#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main(void) {
	printf("size of intmax_t = %jd\n", (intmax_t)sizeof(intmax_t));
	printf("my pid = %jd\n", (intmax_t)getpid());
	printf("my parent's pid = %jd\n", (intmax_t)getppid());

	return 0;
}
