#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/signalhandler.h"

int executer(char **args) {
	if (strcmp(args[0], "cd") == 0) {
		if (chdir(args[1]) == -1) {
			perror("cd");
			return -1;
		}
		return 0;
	}
	else if (strcmp(args[0], "exit") == 0) {
		exit(EXIT_SUCCESS);
	}

	int status;
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		return -1;
	}
	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}

	do {
		if (waitpid(pid, &status, WUNTRACED) == -1) {
			break;
		}
		if (WIFEXITED(status)) {
			return WEXITSTATUS(status);
		}
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	return 0;
}
