#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int sigblocker(int sig) {
	if (sig == 0) {
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_SETMASK, &set, NULL);
	}

	return 0;
}

int killer(int who) {
	kill(who, SIGKILL);
	return 0;
}
