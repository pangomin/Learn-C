#include "headers/parser.h"
#include "headers/readline.h"
#include "headers/executer.h"
#include "headers/cdbuiltin.h"
#include "headers/signalhandler.h"
#include <stddef.h>
#include <stdlib.h>

int main(void) {
	sigblocker(0);
	int status;
	do {
		char *line = readline();
		char **args = parser(line);
			if(args == NULL) {
				;
		} else {
			status = executer(args);
			if (status == -1) {
				;
			}
		}
	} while(1);

	exit(EXIT_FAILURE);
}
