#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	siginfo_t info;

	for(int i = 0; i < 3; i++) {
		pid = fork();
		if(pid == -1) {
			perror("fork");
			printf("Child:%d died\n", getpid());
		} else if (pid == 0) {
			printf("Child: %d PPID: %d\n", getpid(), getppid());
			return 0;
		} else {
			if (waitid(P_PID, pid, &info, WEXITED) == -1) {
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
	}

	return 0;
}
