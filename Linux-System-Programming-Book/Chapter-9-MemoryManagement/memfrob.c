#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>

int main(void) {
	char str[] = "0";

	long unsigned int i;
	for(i = 0; i < strlen(str); i++) {
		str[i] ^= 42;
		printf("%d", str[i]);
	}

	return 0;
}
