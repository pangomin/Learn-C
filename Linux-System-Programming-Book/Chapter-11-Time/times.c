#include <stdio.h>
#include <sys/times.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fd;
	struct tms ts;
	clock_t clock;

	clock =	times(&ts);
	if (clock == (clock_t) -1) {
		perror("times");
		return 1;
	}

	fd = open("/dev/null", O_WRONLY);
	char buf = 's';

	for(long unsigned int i = 0; i < 100000000; i++);
	for(int i = 0; i < 1000000; i++) {
		write(fd, &buf, 1);
	}

	clock =	times(&ts);
	if (clock == (clock_t) -1) {
		perror("times");
		return 1;
	}

	printf("user: %.2f system: %.2f", (double)ts.tms_utime, (double)ts.tms_stime);
}
