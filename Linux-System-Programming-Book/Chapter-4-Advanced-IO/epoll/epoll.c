#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <errno.h>

int main(void)
{
	struct epoll_event event;
	int epfd;

	epfd = epoll_create1 (0);
	if (epfd < 0) {
		perror("epoll_create1");
		return 1;
	}

	int fd = STDIN_FILENO;
	ssize_t nr;
	event.events = EPOLLIN;
	event.data.fd = fd;

	nr = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
	if (nr) {
		perror("epoll_ctl");
		return 1;
	}
	int nr_events;
	for (;;) {
		nr_events = epoll_wait(epfd, &event, 1, 5000);

		if (nr_events < 0) {
			perror("epoll_wait");
			return 1;
		}
		if (nr_events == 0) {
			printf("\nTimeout! retrying...\n");
			continue;
		}

		char buf[100];
		ssize_t ret = read(event.data.fd, buf, sizeof(buf) - 1);

		if (ret == 0) {
			printf("\nEOF\n");
			close(epfd);
			return 0;
		}
		if (ret == -1) {
			if (errno == EINTR)
				continue;
			perror("read");
			close(epfd);
			return 0;
		}
		if (ret > 0) {
			buf[ret] = '\0';
		if (strcasecmp(buf, "exit\n") == 0) {
			puts("Exiting..");
			close(epfd);
			return 0;
		}
			printf("epoll_wait returned %d\n", nr_events);
			printf("fd %d is ready\n", event.data.fd);
			printf("read: %ld %s", ret, buf);
		}


	}
	close(epfd);

	return 0;
}
