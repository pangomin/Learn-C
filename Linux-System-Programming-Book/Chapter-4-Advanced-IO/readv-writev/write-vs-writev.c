#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/uio.h>

#define BUF 1024
#define LOOP_ROUND 10

void time_delta (struct timespec t1, struct timespec t2, struct timespec *delta);

int main(void)
{
	struct timespec wstart, wfinish, wdelta;

	int fd = open ("data", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1) {
		perror("open");
		return 1;
	}

	char buf[BUF];
	memset(buf, '0', sizeof(buf));
	ssize_t ret, nr;
	ssize_t len = strlen(buf);
	nr = sizeof(buf);
	char *buf_p = buf;
	while (len != 0 && (ret = write(fd, buf_p, BUF)) != 0)
	{
		if (ret == -1) {
			if (errno == EINTR)
				continue;
			perror("write");
			break;
		}
		BUF -+ ret;
		buf_p += ret;
		printf("%ld\n", sizeof(buf));
		printf("%ld\n", ret);
		printf("%p\n", buf_p);
	}


	clock_gettime(CLOCK_REALTIME, &wstart);

	clock_gettime(CLOCK_REALTIME, &wfinish);
	time_delta(wstart, wfinish, &wdelta);
	printf("\nwrite: %d.%.9ld\n", (int)wdelta.tv_sec, wdelta.tv_nsec);

	sleep(1);

/*	static struct iovec iov[BUF];
	for (size_t i = 0; i < MAX_BUF_ELEMENTS; i++)
	{
		iov[i].iov_base = buf[i];
		iov[i].iov_len = strlen(buf[i]);
	}
	ssize_t br;
	ssize_t length = 0;
	ssize_t max = 0;
	while (max <= MAX_BUF_ELEMENTS)
	{
//		br = writev(fd, iov, 1024);
		max += 1024;
	}
	if (br == -1) {
		perror("write");
		if (errno == EINVAL) {
			perror("ENIVAL");
			return 1;
		}
		return 1;
	} */
	return 0;
}

enum {NS_PER_SECOND = 1000000000};
void time_delta (struct timespec t1, struct timespec t2, struct timespec *delta) {
	delta->tv_nsec = t2.tv_nsec - t1.tv_nsec;
	delta->tv_sec = t2.tv_sec - t1.tv_sec;

	if (delta->tv_nsec < 0 && delta->tv_sec > 0)
	{
		delta->tv_nsec += NS_PER_SECOND;
		delta->tv_sec--;
	}
	return;
}
