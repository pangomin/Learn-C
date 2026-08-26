#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *stream;
	size_t nr;
	char buf[BUFSIZ];
	char buf2[BUFSIZ];

	stream = fopen("./src", "r");
	if (stream == NULL) {
		perror("fopen");
		return 1;
	}
	nr = fread(buf, sizeof(char), BUFSIZ, stream);
	if (ferror(stream)) {
		puts("Error on stream!");
		return 1;
	}

	memmove(buf2, buf, nr);
	printf("%s", buf2);

	if (fclose(stream)) {
		perror("fclose");
	}

	return 0;
}
