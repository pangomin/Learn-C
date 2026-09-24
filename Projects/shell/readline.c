#include "headers/readline.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *readline(enum readline_status *rlstatus) {
	fputs("[shell] $ ", stdout);
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1) {
		if (feof(stdin)) {
			*rlstatus = READLINE_EOF;
			return NULL;
		} else {
			perror("shell: getline\n");
			*rlstatus = READLINE_ERROR;
			return NULL;
		}
	}
	*rlstatus = READLINE_OK;
	return line;
}
