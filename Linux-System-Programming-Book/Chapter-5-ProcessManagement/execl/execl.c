#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
	int ret = execl("/bin/df", "-h", "-xtmpfs",NULL);
	if (ret < 0) {
		perror("execl");
		return 1;
	}
	return 0;
}
