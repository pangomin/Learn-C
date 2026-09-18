#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DELIMITER " \t\r\n\a"
char **parser(char *input) {
	if (input == NULL) {
		goto error;
	}

	int position = 0;

	/* Allocate as much as the input length plus an space
	 * for NULL each char* bytes size
	 */
	char **args = malloc((strlen(input) + 1) * sizeof(char*));
	if (args == NULL) {
		perror("malloc");
		goto error;
	}

	/* Read the first token. Move position forward and read the
	 * next token. Then post-increament moves position forward,
	 * while the last position is not NULL. If it is, returns
	 * args.
	 */
	args[position] = strtok(input, DELIMITER);

	if (args[position] != NULL) {
		position++;
		do {
			args[position++] = strtok(NULL, DELIMITER);
		} while (args[position-1] != NULL);

		return args;
	}
error:
	return NULL;
}
