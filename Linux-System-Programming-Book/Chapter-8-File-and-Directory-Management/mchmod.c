#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Usage: %s <FILE>", argv[0]);
		return 1;
	}
	int ret;

	ret = chmod(argv[1], S_IRUSR | S_IWUSR);
	if(ret) {
		perror("chmod");
		return 1;
	}
	return 0;
}
