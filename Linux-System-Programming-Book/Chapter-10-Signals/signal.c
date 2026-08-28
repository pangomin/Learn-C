#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	if (signal(SIGINT, SIG_IGN) == SIG_ERR) {
		fprintf(stderr, "Cannot handle SIG_IGN!\n");
		exit(EXIT_FAILURE);
	}
	puts("SIGINT will be ignored. Good lock!");
	for(;;) {
		pause();
	}
	return 0;
}
