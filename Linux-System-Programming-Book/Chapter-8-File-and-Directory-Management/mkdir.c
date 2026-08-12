#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void) {
	int ret;
	ret = mkdir("./dir", 0);
	if(ret == -1) {
		perror("mkdir");
		return 1;
	}
}
