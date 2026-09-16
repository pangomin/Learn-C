#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	char **args = malloc(strlen(input) + 1);
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

void executer(char **args) {
	pid_t pid = fork();
	if (pid == 0) {
		execvp(args[0], args);
	}
}

void main(void) {
	char *line = readline();
	char **args = parser(line);
	if(args == NULL) {
		return;
	}
	executer(args);
}
