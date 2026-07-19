#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_system(char *cmd)
{
	int status;
	pid_t pid;
	pid = fork();

	if(pid == -1) {
		perror("fork");
		return -1;
	} else if(pid == 0) {
		char* argv[4];

		argv[0] = "sh";
		argv[1] = "-c";
		argv[2] = cmd;
		argv[3] = NULL;

		execv("/bin/sh", argv);

		return 0;
	}
	if(waitpid(pid, &status, 0) == -1) {
		perror("waitpid");
		return -1;
	} else if(WIFEXITED(status)) {
		return WIFEXITED(status);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		puts("you need at least one argument");
		return 0;
	} else {
		int ret;
		ret = my_system(argv[1]);
		if(ret == -1) {
			puts("my_system failed");
		}
	}
	return 0;
}
