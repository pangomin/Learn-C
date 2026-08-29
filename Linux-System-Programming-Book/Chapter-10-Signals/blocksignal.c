#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_SETMASK, &set, NULL);

	puts("You cannot raise SIGINT\nThe process kills itself after 5 seconds");
	sleep(5);

	return 0;
}
