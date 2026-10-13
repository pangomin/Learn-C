#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

int main(void)
{
	struct termios terattr, terattr_bak;
	char *cursor_pos = "\e[s";
	char *setcursor_pos = "\e[999999;999999H";
	char *rcursor_pos = "\e[6n";
	char ret[100];
	int row, col, i = 0;

	/* save terminal attributes and set it to ECHO mode, then restore them */
	tcgetattr(STDIN_FILENO, &terattr);
	terattr_bak = terattr;

	terattr.c_lflag &= ~ECHO;
	terattr.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &terattr);

	write(STDOUT_FILENO, setcursor_pos, strlen(setcursor_pos));
	write(STDOUT_FILENO, rcursor_pos, strlen(rcursor_pos));

	while(i < 100) {
		read(STDIN_FILENO, &ret[i], 1);
		if (ret[i] == 'R') {
			ret[i+1] = '\0';
			sscanf(ret, "\e[%d;%dR", &row, &col);
			printf("\nrow: %d col: %d\n", row, col);
			break;
		}
		i++;
	}

	printf("\e[20;20H");
	for (int i = 0; i < 10; i++) {
		printf("*");
	}
	printf("\e[20;20H");
	printf("\e[1B");
	for (int i = 0; i < 10; i++) {
		if (i == 0 || i == 9) {
			printf("*");
		}
		else {
			printf(" ");
		}
	}

	tcsetattr (STDIN_FILENO, TCSANOW, &terattr_bak);

	return 0;
}
