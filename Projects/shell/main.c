#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

char *readline(void) {
	fputs("$ ", stdout);
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1) {
		if (feof(stdin)) {
			exit(EXIT_SUCCESS);
		} else {
			perror("shell: getline\n");
			return NULL;
		}
	}
	return line;
}

char **parser(char *input) {
	if (input == NULL) {
		goto error;
	}
	char **args = malloc((strlen(input) + 1) * sizeof(char*));
	int i = 0;

	args[i] = strtok(input, " \n");

	if (args[i] != NULL) {
		i++;
		do {
			args[i++] = strtok(NULL, " \n");
		} while (args[i-1] != NULL);
		return args;
	}
error:
	return NULL;
}

int executer(char **args) {
	int status;
	pid_t pid = fork();
	if (pid == 0) {
		execvp(args[0], args);
	}
	do {
		waitpid(0, &status, WUNTRACED);
	} while(!WIFEXITED(status) && !WIFSIGNALED(status));
	return 0;
}

void main(void) {
	int status;
	do {
		char *line = readline();
		char **args = parser(line);
			if(args == NULL) {
				return;
		}
		status = executer(args);
	} while(status == 0);
}
