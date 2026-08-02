#include <stdio.h>
#include <sched.h>

int main(void) {
	int ret;
	ret = sched_get_priority_min(SCHED_FIFO);
	printf("min=%d\n", ret);
	ret = sched_get_priority_max(SCHED_FIFO);
	printf("max=%d\n", ret);

	return 0;
}
