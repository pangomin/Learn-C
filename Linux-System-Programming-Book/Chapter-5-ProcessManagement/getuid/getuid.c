#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	printf("uid: %d\nguid: %d\neuid:%d\negid: %d\n",
			getuid(), getgid(),
			geteuid(), getegid());
	return 0;
}
