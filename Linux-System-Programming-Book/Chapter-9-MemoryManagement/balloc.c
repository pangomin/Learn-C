#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *balloc(size_t size) {
	if (size == 0) {
		return NULL;
	}

	/* The guy I copied this trick from is very smart */
	size = (size + sizeof(void*) - 1) & ~(sizeof(void*) - 1);

	void*p = sbrk(size);

	return p;
}

int main(void) {
	char *p;
	while(1) {
		p = balloc(60000000);
		for (int i = 0; i < 60000000; i++) {
			p[i] = 'a';
		}
	}
	return 0;
}
