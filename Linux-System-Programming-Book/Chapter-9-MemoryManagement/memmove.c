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
	printf("%s\n", buf2);

	char *search;
	search = memchr(buf2, 'F', BUFSIZ);
	printf("\n\n%p\n", search);
	printf("\n\n%c\n", *search);

	if (fclose(stream)) {
		perror("fclose");
	}

	return 0;
}
