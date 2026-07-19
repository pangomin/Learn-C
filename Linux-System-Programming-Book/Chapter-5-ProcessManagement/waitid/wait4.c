#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
	struct rusage rus;
	pid_t pid = fork();

	if(pid == -1) {
		perror("fork");
	}
	if(pid == 0) {
		printf("Child: %d", getpid());
		return 0;
	}
	if(pid > 0) {
		int status;
		wait4(pid, &status, 0, &rus);
		/* It does not work but I'm not gonna wait more on wait XD */
		printf("%ld", rus.ru_msgrcv);
	}
	return 0;
}
