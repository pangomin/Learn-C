#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void) {
	long hz;
	hz = sysconf(_SC_CLK_TCK);
	if(hz == -1) {
		perror("sysconf");
		return 1;
	}

	printf("%ld\n", hz);

	printf("%ld\n", CLOCKS_PER_SEC);

	return 0;
}
