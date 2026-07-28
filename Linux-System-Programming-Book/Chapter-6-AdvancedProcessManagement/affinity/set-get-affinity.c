#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>

int main(void) {
	printf("sizeof cpu_set_t=%ld\n", sizeof(cpu_set_t));
	cpu_set_t set;
	int cpu, ret;

	CPU_ZERO(&set);
	CPU_SET(0, &set);

	ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);
	if(ret == -1) {
		perror("sched_setaffinity");
	}
	/*
	 * I have to use sched_getaffinity to fill set with
	 * corrent state, not what I was filled in. So I
	 * have to call sched_getaffinity before CPU_ISSET
	 */
	ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);
	if(ret == -1) {
		perror("sched_getaffinity");
	}
	for(int i = 0; i < 28; i++) {
		cpu = CPU_ISSET(i, &set);
		printf("cpu=%d is %s\n", i, cpu ? "set": "unset");
		}
	for(;;);
	return 0;
}
