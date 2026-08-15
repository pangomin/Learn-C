#include <stdio.h>
#include <unistd.h>

int main(void) {
	int ret;
	ret = remove("./torem/");
	if(ret) {
		perror("remove");
		return 1;
	}
	return 0;
}
