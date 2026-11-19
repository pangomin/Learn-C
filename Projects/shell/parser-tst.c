#include "headers/parser.h"
#include "headers/readline.h"
#include <stdlib.h>

int main(void) {
	char *line;
	enum readline_status rlstatus;
	struct parsed_command *cmd;

	line = readline(&rlstatus);
	if (line == NULL) {
		if (rlstatus == READLINE_EOF) {
			free(line);
			return 0;
		}
		if (rlstatus == READLINE_ERROR) {
			free(line);
			return 0;
		}
	}
	else {
		cmd = parser(line);
	}
}
