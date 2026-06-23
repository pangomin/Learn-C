#include <stdio.h>
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
	ssize_t ret;
	char buf[100];
	char *buf_ptr = buf;
	ssize_t len = sizeof(buf);
	for (;;) {
		nr_events = epoll_wait(epfd, &event, 1, 1000);
		if (nr_events < 0) {
			perror("epoll_wait");
			return 1;
		}
		while (len != 0 && (ret = read(event.data.fd, buf_ptr, len != 0)))
		{
		if (ret == 0) {
			break;
		}
		if (ret == -1) {
			if (errno == EINTR) {
				continue;
		}
			perror("read");
			return 1;
			}
			len -= ret;
			buf_ptr += ret;
		}
	}
	close(epfd);

	return 0;
}
