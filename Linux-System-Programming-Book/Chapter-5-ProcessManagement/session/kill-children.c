#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sched.h>

int main(void) {
	printf("Parent pid=%d pgid=%d\n", getpid(), getpgid(0));
	pid_t pid = fork();
	if(pid == -1) {
		perror("fork"); return -1;
	}
	if(pid > 0) {
		pid_t pid2 = fork();

		if(pid2 > 0) {
			if(setpgid(pid, pid) == -1) {
				perror("setpgid");
			}
			if(setpgid(pid2, pid) == -1) {
				perror("setpgid");
			}

		}
		if(pid2 == -1) {
			perror("fork"); return -1;
		}

		if(pid2 == 0) {
			sleep(3);
			while(1) {
				printf("pid2 %d\npgid %d\n", getpid(), getpgid(0));
				kill(getpid(), SIGTERM);
			}
		}
	}
	if(pid == 0) {
		sleep(3);
		while(1) {
			printf("pid %d\npgid %d\n", getpid(), getpgid(0));
			kill(getpid(), SIGTERM);
		}
	}
	sleep(6);
	return 0;
}
