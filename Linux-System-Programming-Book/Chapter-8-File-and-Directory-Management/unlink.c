#include <stdio.h>
#include <unistd.h>

int main(void) {
	int ret;
	ret = unlink("./link");
	if(ret) {
		perror("unlink");
		return 1;
	}
	return 0;
}
