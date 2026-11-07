#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	char *data;
	int numbers[100];
	size_t nr = 0;
	ssize_t ret = 0;

	ret = getline(&data, &nr, stdin);
	if (ret == -1) {
		if (ferror(stdin)) {
			perror("getline");
			free(data);
			return 1;
		}
	}

	int i = 0;
	data[ret] = '\0';
	while (data[i] != '\0') {
		numbers[i] = data[i] - '0';
		printf("%d\n", numbers[i]);
		i++;
	}

	free(data);

	return 0;
}
