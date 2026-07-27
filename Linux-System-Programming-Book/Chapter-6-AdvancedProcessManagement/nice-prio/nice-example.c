#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
	int ret;
	errno = 0;
	ret = nice(19);
	if(ret == -1 && errno != 0) {
		perror("nice");
	} else {
		printf("%d", ret);
	}
	return 0;
}
