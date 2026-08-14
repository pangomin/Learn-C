#include <unistd.h>
#include <stdio.h>

int main(void) {
	int ret;
	ret = link("./chdir", "../chdirlink");
	if(ret == -1) {
		perror("link");
		return 1;
	}
	return 0;
}
