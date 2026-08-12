#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	if(argc < 2) {
		puts("fuck");
		return 1;
	}
	DIR *dirstream;
	int fddir;
	struct dirent *readdir_content;

	dirstream = opendir(argv[1]);
	if(dirstream == NULL) {
		perror("opendir");
		return 1;
	}

	fddir = dirfd(dirstream);
	if(fddir == -1) {
		perror("dirfd");
		return 1;
	}
	printf("fddir=%d\n", fddir);

	errno = 0;
	while(1) {
		readdir_content = readdir(dirstream);
		if(readdir_content == NULL) {
			if(errno != 0) {
				perror("readdir");
				return -1;
			}
			break;
		}
		printf("%s\n", readdir_content->d_name);
	}

	if(closedir(dirstream)) {
		perror("closedir");
		return 1;
	}

	return 0;
}
