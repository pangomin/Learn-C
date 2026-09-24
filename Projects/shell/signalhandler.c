#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int sigblocker(int signo) {
	sigset_t set;
	int ret;

	if (sigprocmask(SIG_BLOCK, NULL, &set) != 0) {
		return -1;
	}

	ret = sigismember(&set, signo);
	if (ret == -1) {
		perror("sigismember");
		return -1;
	}
	else if (ret == 1) {
		return 0;
	}
	else {
		if (sigemptyset(&set) == -1) {
			perror("sigemptyset");
			return -1;
		}
		else if (sigaddset(&set, signo) == -1) {
		return -1;
		}
		else {
			ret = sigprocmask(SIG_BLOCK, &set, NULL);
			if (ret != 0) {
				return -1;
			}
			else {
			return 0;
			}
		}
	}
}

int sigcleaner(int sig) {
	sigset_t current;
	int ret;
	if (sigprocmask(SIG_BLOCK, NULL, &current) != 0) {
		return -1;
	}

	ret = sigismember(&current, sig);
	if (ret == -1) {
		perror("sigismember");
		return -1;
	} else if (ret == 1) {
		sigemptyset(&current);
		sigaddset(&current, sig);
	} else {
		puts("signal is not a member");
		return -1;
	}

	if (sigprocmask(SIG_UNBLOCK, &current, NULL) != 0) {
		return -1;
	}
	else {
		return 0;
	}
}
