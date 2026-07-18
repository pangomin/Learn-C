#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	siginfo_t infop;
	int status;

	for(int i = 0; i < 3; i++) {
		pid = fork();
		if(pid == -1) {
			perror("fork");
			printf("Child:%d died\n", getpid());
		} else if (pid == 0) {
			printf("Child: %d PPID: %d\n", getpid(), getppid());
			return 42;
		} else {
			status = waitid(P_PID, pid, &infop, WEXITED);
			if(status == -1) {
				perror("waitid");
			}
			if(status == 0) {
				printf("Normal termination for PID %d\n\
		Exit code=%d\n\
		si_code=%d\n\
		si_status=%d\n",
		infop.si_pid,
		infop.si_signo,
		infop.si_code,
		infop.si_status);
			}
		}
	}

	return 0;
}
