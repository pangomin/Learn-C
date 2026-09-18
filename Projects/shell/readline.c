#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *readline(void) {
	fputs("[shell] $ ", stdout);
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1) {
		if (feof(stdin)) {
			;
		} else {
			perror("shell: getline\n");
			return NULL;
		}
	}
	return line;
}
