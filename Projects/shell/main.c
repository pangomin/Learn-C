#include "headers/parser.h"
#include "headers/readline.h"
#include "headers/executer.h"
#include "headers/cdbuiltin.h"
#include "headers/signalhandler.h"
#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	sigblocker(SIGINT);
	sigblocker(SIGTSTP);
	char *line;
	enum readline_status rlstatus;
	struct parsed_command *cmd;

	/* read input, parse and execute it */
	do {
		line = readline(&rlstatus);
		if (line == NULL) {
			if (rlstatus == READLINE_EOF) {
				free(line);
				exit(EXIT_SUCCESS);
			}
			if (rlstatus == READLINE_ERROR) {
				free(line);
				continue;
			}
		} else {
			cmd = parser(line);
			if (cmd == NULL) {
				free(line);
				continue;
			}
			if (executer(cmd) == -1) {
				free(cmd);
				free(line);
				continue;
			}
		}
		free(cmd);
		free(line);
	} while(1);

	exit(EXIT_FAILURE);
}
