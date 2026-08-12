#include <unistd.h>
#include <stdio.h>

int main(void) {
	int ret = rmdir("./dir");
	if(ret == -1) {
		puts("Dead");
		return 1;
	}
	return 0;
}
