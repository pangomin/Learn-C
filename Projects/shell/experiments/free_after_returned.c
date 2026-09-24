#include <stdio.h>
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

int main(void)
{
	for(;;) {
	char *line = malloc(1000*sizeof(char));
	line = readline();
	free(line);
	}
}
