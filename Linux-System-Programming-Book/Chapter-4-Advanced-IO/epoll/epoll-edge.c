#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>


int main(void) {
	struct epoll_event event;
	int epfd;
	int fd = STDIN_FILENO;
	ssize_t nr;
	int nr_events;
	char buf[3];
	ssize_t ret;

	fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);

	epfd = epoll_create1 (0);
	if (epfd < 0) {
		perror("epoll_create1");
		return 0;
	}

	event.events = EPOLLET | EPOLLIN;
	event.data.fd = fd;

	nr = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
	if (nr) {
		perror("epoll_ctl");
		return 0;
	}

	for (;;) {
		nr_events = epoll_wait(epfd, &event, 1, 5000);
		if (nr_events < 0) {
			perror("epoll_wait");
			return 0;
		}
		if (nr_events == 0) {
			printf("\ntimeout! retrying...\n");
			continue;
		}
		while (1) {
			ret = read(event.data.fd, buf, sizeof(buf) - 1);

			if (ret > 0) {
				buf[ret] = '\0';
				printf("epoll_wait returned %d\n", nr_events);
				printf("fd %d is ready\n", event.data.fd);
				printf("read: %ld bytes: %s\n", ret, buf);
				puts("------------------");
			}
			else if (ret == 0) {
				printf("\nEOF\n");
				close(epfd);
				return 0;
			}
			else {
				if (errno == EINTR) continue;
					if (errno == EAGAIN || errno == EWOULDBLOCK) {
					break;
					}
				perror("read");
				close(epfd);
				return 0;
				}
			}

	}
	close (epfd);
	return  0;
}
