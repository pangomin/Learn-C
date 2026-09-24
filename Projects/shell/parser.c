#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/parser.h"

#define DELIMITER " \t\r\n\a"

	/* Tokenize input using DELIMITER. On success, returns a pointer to a parsed_command
	 * struct. On error, returns NULL.
	 */
struct parsed_command *parser(char *input)
{
	if (input == NULL) {
		return NULL;
	}

	int position = 0;
	struct parsed_command *cmd;

	/* Allocate from heap to cmd so it can survive after function died */
	cmd = malloc(sizeof(struct parsed_command));
	if (cmd == NULL) {
		perror("malloc");
		return NULL;
	}

	/* Allocate an array of char* to hold pointers to tokens.
	 * For now it allocates more than needed.
	 */
	char **args = malloc((strlen(input) + 1) * sizeof(char*));
	if (args == NULL) {
		free(cmd);
		perror("malloc");
		return NULL;
	}

	/* Tokenize input string and store each pointer to token in an array. It handles shell
	 * redirection and stores file name to filename field. Returns struct fields on success
	 * and NULL on error.
	 */
	args[position] = strtok(input, DELIMITER);

	if (args[position] != NULL) {
		position++;
		do {
			args[position] = strtok(NULL, DELIMITER);
			if (args[position] == NULL) {
				cmd->args = args;
				cmd->filename = NULL;
				return cmd;
			}
			else if (strcmp(args[position], ">") == 0) {
				args[position] = NULL;
				cmd->args = args;
				position++;
				cmd->filename = strtok(NULL, DELIMITER);
				if (cmd->filename == NULL) {
					fprintf(stderr, "shell expected an string!\n");
					free(args);
					free(cmd);
					return NULL;
				}

				return cmd;
			}
			else
			{
				position++;
			}
		} while (args[position-1] != NULL);
		cmd->filename = NULL;
		cmd->args = args;
		return cmd;
	}
	/* free args and cmd before returning NULL */
	free(args);
	free(cmd);
	return NULL;
}
