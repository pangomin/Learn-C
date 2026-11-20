#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

void move_cursor(int row, int col) {
	write(STDOUT_FILENO, "\e[s", strlen("\e[s"));
	write(STDOUT_FILENO, "\e[6n", strlen("\e[6n"));

	int l_row = 0, l_col = 0;

	char ret[128];
	int i = 0;
	while(i < 128) {
		read(STDIN_FILENO, &ret[i], 1);
		if (ret[i] == 'R') {
		 ret[i+1] = '\0';
			if (sscanf(ret, "\e[%d;%dR", &l_row, &l_col) == 2) {
				  break;
			}
			else {
				fprintf(stderr, "sscanf failed!\n");
				return;
			}
		}
		i++;
	}

	if (row > 0) {
		printf("\e[%d;%dH", row, l_row);
		fflush(stdout);
	}
	if (col > 0) {
		printf("\e[%d;%dH", l_row, col);
		fflush(stdout);
	}
	if ((row && col) > 0) {
		printf("\e[%d;%dH", row, col);
		fflush(stdout);
	} else {
		fprintf(stderr, "Invalid value!\n");
		return;
	}

	return;
}

int main(void)
{
	struct termios terattr = {0}, terattr_bak = {0};
	char key = '\0';

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
	int x = 40;
	int y = 40;

	while (key != 'q') {
		key = fgetc(stdin);
		switch(key)
		{
case 'a': move_cursor(--y, --x); break;
default: continue;
		}
	}

	if (tcsetattr (STDIN_FILENO, TCSANOW, &terattr_bak) < 0) {
		perror("tcsetattr old attr");
		return 1;
	}

	return 0;
}
