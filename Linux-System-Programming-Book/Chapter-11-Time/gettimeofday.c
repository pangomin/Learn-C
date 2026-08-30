#include <stdio.h>
#include <sys/time.h>

int main(void) {
	struct timeval tv;
	int ret;

	ret = gettimeofday(&tv, NULL);
	if (ret) {
		perror("gettimeofday");
		return 1;
	}
	printf("sec=%ld usec=%ld\n", tv.tv_sec, tv.tv_usec);
}
