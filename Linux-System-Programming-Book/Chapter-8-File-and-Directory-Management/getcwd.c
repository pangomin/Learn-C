#include <stdio.h>
#include <unistd.h>

int main(void) {
	char buf[1024];
	if(getcwd(buf, 1024) == NULL) {
		perror("getcwd");
		return 1;
	}
	fputs(buf, stdout);
	return 0;
}
