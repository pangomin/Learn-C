#include <unistd.h>
#include <stdio.h>

int cd(char *path) {
	if (path == NULL)
	{
		chdir(".");
		return 0;
	}
	else {
		if (chdir(path)) {
			perror("chdir: ");
			return -1;
		}
	}
	return 0;
}
