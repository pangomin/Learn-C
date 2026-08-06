#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *start_thread(void *message) {
	printf("%s\n", (const char*) message);
	return message;
}

int main(void) {
	pthread_t t1, t2;
	const char *message1 = "t1";
	const char *message2 = "t2";

	pthread_create(&t1, NULL, start_thread, (void*) message1);
	pthread_create(&t2, NULL, start_thread, (void*) message2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
