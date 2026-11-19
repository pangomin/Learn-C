#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

int main(void)
{
	struct termios terattr = {0}, terattr_bak = {0};
	if (tcgetattr(STDIN_FILENO, &terattr) < 0) {
		perror("tcgetattr");
		return 1;
	}
	terattr_bak = terattr;

	terattr.c_lflag &= ~ECHO;
	terattr.c_lflag &= ~ICANON;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &terattr) < 0) {
		perror("tcsetattr ICANON");
		return 1;
	}

	char key;
	while (key != 'q') {
		key = fgetc(stdin);
		switch(key)
		{
			case 'd': printf(" "); break;
			case 'w': printf("WWWW"); break;
		}
	}

	if (tcsetattr (STDIN_FILENO, TCSANOW, &terattr_bak) < 0) {
		perror("tcsetattr old attr");
		return 1;
	}

	return 0;
}
