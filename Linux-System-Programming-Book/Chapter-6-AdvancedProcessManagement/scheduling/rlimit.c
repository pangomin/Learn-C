#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1048577
#define RLIM_SIZE 1048576

int main(void) {
	struct rlimit lim;
	int ret;
	int fd;
	char buf[MAX_FILE_SIZE];

	lim.rlim_cur = RLIM_SIZE;
	lim.rlim_max = RLIM_SIZE;

	ret = setrlimit(RLIMIT_FSIZE, &lim);
	if(ret == -1 && lim.rlim_max != RLIM_INFINITY) {
		perror("setrlimit");
		return 1;
	}

	fd = open("rlim_test", O_CREAT | O_WRONLY);
	if(fd == -1) {
		perror("open");
		return 1;
	}
	// yes it is slow but who cares
	for(int i = 0; i < MAX_FILE_SIZE; i++) {
		buf[i] = 'i';
		ret = write(fd, buf, 1);
	}
	return 0;
}
