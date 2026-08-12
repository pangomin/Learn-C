#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if(argc < 2) {
		puts("dead");
		return 1;
	}

	char cwd[1024];
	int ret;

	ret = chdir(argv[1]);
	if(ret == -1) {
		perror("chdir");
		return 1;
	}
	if(getcwd(cwd, 1024) == NULL) {
		perror("getcwd");
		return 1;
	}
	fputs(cwd, stdout);
	return 0;
}
