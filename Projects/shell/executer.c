#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "headers/signalhandler.h"
#include "headers/cdbuiltin.h"

/*
 * Execute commands.
 *
 * Builtins, cd and exit, are handled directly. Everything else is forked
 * and runs with execvp. Blocks until the child exits, is signaled, or stops.
 *
 * Returns the child's exit status, the terminating signal number, or
 * the stop signal number; -1 on failure of fork, etc.
 */

int executer(char **args) {
	if (strcmp(args[0], "cd") == 0) {
		if (cd(args[1]) == -1) {
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
		/* Reset SIGINT and SIGTSTP in the child, so it can get intrrupted */
		if ((sigcleaner(SIGINT) | sigcleaner(SIGTSTP)) == 0) {
			if (execvp(args[0], args) == -1) {
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else {
			puts("sigcleaner failed!\n");
			exit(EXIT_FAILURE);
		}
	}
		/* Wait for child and check its status */
		if (waitpid(pid, &status, WUNTRACED) == -1) {
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status)) {
			return WEXITSTATUS(status);
		}
		if (WIFSIGNALED(status)) {
			return WTERMSIG(status);
		}
		if (WIFSTOPPED(status)) {
			return WSTOPSIG(status);
		}
		return -1;
}
