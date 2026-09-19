#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *readline(void) {
	fputs("[shell] $ ", stdout);
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
