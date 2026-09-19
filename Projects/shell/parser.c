#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DELIMITER " \t\r\n\a"

	/* Tokenize input using DELIMITER. On success, returns a NULL-terminated
	* array of to token pointers. On error, returns NULL.
	*/
char **parser(char *input) {
	if (input == NULL) {
		goto error;
	}

	int position = 0;

	/* Allocate an array of char* to hold pointers to tokens.
	 * For now it allocates more than needed.
	 */
	char **args = malloc((strlen(input) + 1) * sizeof(char*));
	if (args == NULL) {
		perror("malloc");
		goto error;
	}

	/* Tokenize input string and store each pointer to token in an array.
	 * Return array on success and NULL on error.
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
