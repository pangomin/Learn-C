#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	char buf[10000];
	memset(buf, '1', sizeof(buf));

	int fd = open("text", O_CREAT | O_RDWR, 0664);
	int newfd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);

	size_t total = sizeof(buf);
	size_t offset = 0;
	while(offset < total) {
		ssize_t nr = write(STDOUT_FILENO, buf + offset, total - offset);
		if(nr < 0) {
			perror("write");
			break;
		}
		offset += nr;
	}
}
