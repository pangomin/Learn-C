#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>

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
	int ret;
	event.events = EPOLLIN;
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
	if (ret)
		perror("epoll_ctl");
	int nr_events;
		nr_events = epoll_wait(epfd, &event, 1, 1000);
		if (nr_events < 0) {
			perror("epoll_wait");
			return 1;
		}
		printf("%d", nr_events);

	return 0;
}
