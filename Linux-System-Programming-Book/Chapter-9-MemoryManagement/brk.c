#include <unistd.h>
#include <stdio.h>

int main(void) {
	void* p = sbrk(sizeof(int));
	printf("%p\n", sbrk(0));
	void* new = (char*) p + 4096;
	brk(new);
	printf("%p\n", sbrk(0));
}
