#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>

int main(void) {
	char buf0[10], buf1[10], buf2[10];
	struct iovec iov[3];
	ssize_t nr;
	int fd;

	fd = open("data.txt", O_RDONLY);
	if (fd == -1) {
		perror ("open");
		return 1;
	}
		iov[0].iov_base = buf0;
		iov[0].iov_len = sizeof(buf0);
		iov[1].iov_base = buf1;
		iov[1].iov_len = sizeof(buf1);
		iov[2].iov_base = buf2;
		iov[2].iov_len = sizeof(buf2);

	nr = readv(fd, iov, 3);
	if (nr == -1) {
		perror("readv");
		return 1;
	}
	for (int i = 0; i < 3; i++) {
		printf("%d: %s\n", i, (char*)iov[i].iov_base);
	}
	if (close(fd)) {
		perror("close");
		return 1;
	}
	return 0;
}
