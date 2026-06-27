#include <stdio.h>
#include <unistd.h>
#include <sys/user.h>

int main(void) {
	int name = 0;
	long page_size2 = sysconf(_SC_PAGESIZE);
	printf("_SC_PAGESIZE (sysconf) = %ld\n", page_size2);
	printf("PAGE_SIZE (hard code) = %ld\n", PAGE_SIZE);
	printf("_SC_PAGESIZE = %d\n", _SC_PAGESIZE);
	printf("_SC_ARG_MAX = %d\n", _SC_ARG_MAX);
	printf("Passing name = 0 to sysconf:  %ld\n", sysconf(name));
	return 0;
}
