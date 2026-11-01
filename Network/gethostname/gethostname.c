#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	size_t size = 1024;
	char *host = malloc(size);

	gethostname(host, size);

	printf("%s", host);

	free(host);

	return 0;
}
