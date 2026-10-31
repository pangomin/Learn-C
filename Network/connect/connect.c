#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	struct addrinfo hints, *res;
	int sockfd;
	char buf[4096];
	const char *req =
		"GET / HTTP/1.1\r\n"
		"Host: google.com\r\n"
		"Connection: close\r\n"
		"\r\n";

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo("google.com", NULL, &hints, &res);

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (sockfd < 0) {
		perror("socket");
		return -1;
	}
	if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
		perror("connect");
		return -1;
	}
	puts("connected");
	size_t sent = 0;
	size_t reqlen = strlen(req);
while (sent < reqlen) {
    ssize_t w = write(sockfd, req + sent, reqlen - sent);
    if (w < 0) { perror("write"); return 1; }
    sent += w;
}

	ssize_t n;

	while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
		fwrite(buf, 1, n, stdout);
	}
	printf("%s", buf);

	return 0;
}
