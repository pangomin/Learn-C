#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CHILD 3

int main(void)
{
	pid_t pid[MAX_CHILD];
	siginfo_t info;

	for(int i = 0; i < MAX_CHILD; i++) {
		pid[i] = fork();

		if(pid[i] == -1) {
			perror("fork");
			printf("Child:%d died\n", getpid());
		} else if(pid[i] == 0) {
			sleep(1); // for now
			printf("Child: %d PPID: %d\n", getpid(), getppid());
			return 0;
		}
	}
	for(int i = 0; i < MAX_CHILD; i++) {
		if(waitid(P_PID, pid[i], &info, WEXITED) == -1) {
			perror("waitid");
		} else {
			printf("Normal termination for PID %d\n\
	si_signo=%d\n\
	si_code=%d\n\
	si_status=%d\n\n",
	info.si_pid,
	info.si_signo,
	info.si_code,
	info.si_status);
			}
	}
	return 0;
}
