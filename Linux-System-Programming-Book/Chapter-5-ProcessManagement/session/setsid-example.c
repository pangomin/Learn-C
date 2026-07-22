#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void) {
	pid_t pid;
	pid_t sid;

	pid = fork();

	if(pid == -1) {
		perror("fork");
		return -1;
	}
	if(pid != 0) {
		exit(EXIT_SUCCESS);
	}
	if(setsid() == -1) {
		perror("setsid");
		return -1;
	}
	sid = getsid(0);
	if(sid == -1) {
		perror("getsid");
		return -1;
	}
	else {
		printf("session id=%d\n", sid);
	}
	while(1);
	/*
	 * I have to figure out why looping after printf while getsid
	 * is sent to printf directly causes printf to not
	 * print the result in terminal
	 * */
}
