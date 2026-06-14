#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

#define BUF_SIZE 3

int main(void) {
	struct iovec iov[BUF_SIZE];
	ssize_t nr;
	int fd;
	char *buf[] = {
		"12345A\n",
		"12345B\n",
		"12345C\n" };
	char *buf2[] = {
		"12345A2\n",
		"12345B2\n",
		"12345C2\n" };
	fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		perror("open");
		return 1;
	}
	printf("buf:		%p\n", buf);
	printf("&buf[0]:	%p\n", &buf[0]);
	printf("*buf:		%p\n", *buf);

	printf("buf[0]:		%p\n", buf[0]);
	printf("*buf[0]:	%c\n", *buf[0]);
	printf("*(&buf[0]):	%p\n", *(&buf[0]));

	printf("buf[1]:		%p\n", buf[1]);
	printf("&buf[1]:	%p\n", &buf[1]);
	printf("*buf[1]:	%c\n", *buf[1]);

	printf("buf[2]:		%p\n\n", buf[2]);

	// Fill out three iovec structures
	size_t buf_length = 0;
	for (int i = 0; i < BUF_SIZE; i++) {
		printf("sizeof buf[%d]: %lu\n", i, sizeof(buf[i]));
		printf("strlen(buf[%d]): %lu\n", i, strlen(*(buf + i)));
		printf("*(buf + %d): %s\n", i, *(buf + i));

		buf_length += strlen(*(buf + i));
		printf("buf length: %d\n", buf_length);
		printf("\n");

		iov[i].iov_base = buf[i];
		iov[i].iov_len = strlen(*(buf + i));
	}
	nr = writev(fd, iov, BUF_SIZE);
	if (nr == -1) {
		perror("writev");
		return 1;
	}
	if (nr != buf_length) {
		fprintf(stderr, "Couldn't write all the buffer");
		return 1;
	}
	printf("First wrote: %zd bytes\n", nr);
	/* Unecessary because of how writev behaves
	int ret = lseek(fd, (off_t) nr, SEEK_SET);
	if (ret == -1) {
		perror("lseek");
		return 1;
	} */
	size_t buf2_length = 0;
	for (int i = 0; i < BUF_SIZE; i++) {
		iov[i].iov_base = buf2[i];
		iov[i].iov_len = strlen(*(buf2 + i));
		buf2_length += strlen(*(buf2 + i));
	}
	nr = writev(fd, iov, BUF_SIZE);
	if (nr == -1) {
		perror("writev");
		return 1;
	}
	if (nr != buf2_length) {
		fprintf(stderr, "Couldn't write all the buffer");
		return 1;
	}

	printf("Second wrote: %zd bytes\n", nr);

	if(close(fd)) {
		perror("close");
		return 1;
	}
	return 0;
}
