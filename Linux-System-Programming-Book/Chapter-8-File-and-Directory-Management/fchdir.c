#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if(argc < 2) {
		puts("Dead");
		return 1;
	}
	char *cwd;
	int ret, fd;

	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("open");
		return 1;
	}
	ret = fchdir(fd);
	if(ret == -1) {
		perror("fchdir");
		return 1;
	}
	cwd = getcwd(NULL, 0);
	if(cwd == NULL) {
		perror("getcwd");
		return 1;
	}

	fputs(cwd, stdout);
	free(cwd);

	return 0;
}
