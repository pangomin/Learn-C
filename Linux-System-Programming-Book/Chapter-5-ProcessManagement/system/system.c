#include <stdlib.h>
#include <stdio.h>

int main(void) {
	if(system("ls") == -1) {
		perror("system");
		return 1;
	}
}
