#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Not enough args\n");
		return 1;
	}
	struct group *gr;
	int ret;

	gr = getgrnam("empower");
	if(!gr) {
		perror("getgrnam");
		return 1;
	}
	printf("name: %s\n", gr->gr_name);
	printf("gid: %d\n", gr->gr_gid);

	ret = chown(argv[1], -1, gr->gr_gid);
	if(ret == -1) {
		perror("chown");
		return 1;
	}
	return 0;
}
