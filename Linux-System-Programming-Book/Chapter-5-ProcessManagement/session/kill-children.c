#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sched.h>
#include <sys/wait.h>

int main(void) {
	printf("Parent pid=%d pgid=%d\n", getpid(), getpgid(0));

	int pipefd[2];
	if(pipe(pipefd) == -1) {
		perror("pipe");
		return -1;
	}

	pid_t pid = fork();
	if(pid == -1) {
		perror("fork");
		return -1;
	}

	if(pid == 0) {
		close(pipefd[1]);

		char buf;
		ssize_t nr = read(pipefd[0], &buf, 1);
		if(nr == -1) {
			perror("read");
			return -1;
		}

		printf("P1: pid %d\nP1: pgid %d\n", getpid(), getpgid(0));
		return 0;
	}

	pid_t pid2 = fork();

	if(pid2 == -1) {
		perror("fork");
		return -1;
	}

	if(pid2 == 0) {
		close(pipefd[1]);

		char buf;
		ssize_t nr = read(pipefd[0], &buf, 1);
		if(nr == -1) {
			perror("read");
			return -1;
		}

		printf("P2: pid2 %d\nP2: pgid %d\n", getpid(), getpgid(0));
		return 0;
	}

	/* Parent */
	close(pipefd[0]);

	if(setpgid(pid, getpgid(0)) == -1) {
		perror("setpgid");
	}

	if(setpgid(pid2, getpgid(0)) == -1) {
		perror("setpgid");
	}

	char c = 'r';
	ssize_t nr = write(pipefd[1], &c, 1);
	if(nr == -1) {
		perror("write");
		return -1;
	}

	nr = write(pipefd[1], &c, 1);
	if(nr == -1) {
		perror("write");
		return -1;
	}

	wait(NULL);
	wait(NULL);

	return 0;
}
