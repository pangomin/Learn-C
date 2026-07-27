#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main(void) {
	int ret;
	errno = 0;
	ret = setpriority(PRIO_PGRP, 0, 10);

	if(ret == -1 && errno != 0) {
		perror("setpriority");
	}

	ret = getpriority(PRIO_PGRP, 0);

	if(ret == -1) {
		perror("getpriority");
	} else {
		printf("prio=%d\nPGRP=%d\nPRIO_PROCESS=%d\nPRIO_USER=%d\n",
				ret, PRIO_PGRP, PRIO_PROCESS, PRIO_USER);
	}
}
