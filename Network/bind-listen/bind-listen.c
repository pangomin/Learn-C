#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	struct addrinfo hints, *res;
	int sockfd;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if (getaddrinfo(NULL, "8080", &hints, &res)) {
		perror("getaddrinfo");
		return -1;
	}

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (sockfd < 0) {
		perror("sockfd");
		return -1;
	}

	if (bind(sockfd, res->ai_addr, res->ai_addrlen)) {
		perror("bind");
		return -1;
	}

	int yes = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes))) {
		perror("setsockopt");
		return -1;
	}

	if (listen(sockfd, 1)) {
		perror("listen");
		return -1;
	}
	sleep(10);
	return 0;
}
