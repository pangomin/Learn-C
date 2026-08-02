#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main(void) {
	struct sched_param sp = {.sched_priority = 1};
	int param;
	param = sched_setscheduler(0, SCHED_FIFO, &sp);
	if(param == -1) {
		perror("sched_setscheduler");
		return -1;
	}
	printf("sched=%d\n", sched_getscheduler(getpid()));
	printf("SCHED_RR=%d\n", SCHED_FIFO);
}
