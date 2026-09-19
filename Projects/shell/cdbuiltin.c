#include <unistd.h>
#include <stdio.h>

int cd(char *path) {
	if (chdir(path)) {
		perror("chdir: ");
		return -1;
	}
	return 0;
}
