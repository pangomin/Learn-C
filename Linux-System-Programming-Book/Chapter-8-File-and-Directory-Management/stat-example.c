#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Usage: %s <FILE> <OPTIONS>", argv[0]);
		return 1;
	}

	int fd, ret;
	int opt = 0;
	struct stat stats;

	fd = open(argv[1], O_WRONLY);
	if(fd == -1) {
		perror("open");
		return 1;
	}
	ret = fstat(fd, &stats);
	if(ret == -1) {
		perror("stat");
		return 1;
	}
	while((opt = getopt(argc, argv, "i:b:p:")) != -1 && argc != 0)
	{
		switch(opt) {
case 'i': printf("inode number=%ld\n", stats.st_ino); break;
case 'b': printf("size=%ld\n", stats.st_size); break;
case 'p': printf("Permissions=%d\n", stats.st_mode); break;
case '?': fprintf(stderr, "unknown option: %c\n", optopt); return 1;
default: fprintf(stderr, "not enough argument\n"); return 1;
		}
		--argc;
		++argv;
	}
	if(close(fd)) {
		perror("close");
	}
	return 0;
}
