#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main(void) {
	struct sched_param sp;
	int ret;
	ret = sched_getparam(0, &sp);
	if(ret == -1) {
		perror("sched_getparam");
		return -1;
	}
	printf("priority=%d\n", sp.sched_priority);

	sp.sched_priority = 1;

	ret = sched_setscheduler(0, SCHED_FIFO, &sp);
	if(ret == -1) {
		perror("sched_setscheduler");
		return -1;
	}
	sp.sched_priority = 60;

	ret = sched_setparam(0, &sp);
	if (ret == -1) {
		perror("sched_setparam");
		return -1;
	}
	printf("new priority=%d\n", sp.sched_priority);
	return 0;
}
