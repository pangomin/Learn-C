#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	int status;
	pid_t pid = fork();
	pid_t waitpd;

	if(pid == -1) {
		perror("fork");
		return 1;
	}
	if(pid == 0) {
		printf("childpid=%d\n", getpid());
		printf("parentpid=%d\n", getppid());
	}
	if(pid > 0) {
		waitpd = waitpid(pid, &status, 0);
		if(waitpd == -1) {
			perror("waitpid");
			return 1;
		} else {
			printf("waitpid=%d\n", waitpd);
			if(WIFEXITED(status)) {
				printf("Normal termination with exit status: %d\n",
					WEXITSTATUS(status));
			}
		}
	}
	return 0;
}
