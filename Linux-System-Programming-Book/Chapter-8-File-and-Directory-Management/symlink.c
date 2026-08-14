#include <stdio.h>
#include <unistd.h>

int main(void) {
	int ret = symlink("/home/beny/Desktop/C/Learn-C/Linux-System-Programming-Book/Chapter-8-File-and-Directory-Management/chdir", "../chdir.link");
	if(ret == -1) {
		perror("symlink");
		return 1;
	}
	return 0;
}
