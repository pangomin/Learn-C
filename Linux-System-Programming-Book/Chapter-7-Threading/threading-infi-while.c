#include <stdio.h>
#include <pthread.h>

#define THREAD 27

void *loop(void*) {
	while(1);
}
int main(void) {
	pthread_t t[THREAD];

	for(int i = 0; i < THREAD; i++) {
		printf("starting t[%d]\n", i);
		pthread_create(&t[i], NULL, loop, NULL);
	}
	while(1);
}
