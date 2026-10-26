#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s hostname", argv[0]);
		return -1;
	}
	int status;
	struct addrinfo hints;
	struct addrinfo *res;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
		fprintf(stderr, "getaddrinfo %s\n", gai_strerror(status));
		return 0;
	}
	for (int i = 0; i < res->ai_addrlen; i++) {
		if (i > 1 && i < 6) {
			printf("%d", (unsigned char)res->ai_addr->sa_data[i]);
		if (i < 5) printf(".");
		}
	}
}
