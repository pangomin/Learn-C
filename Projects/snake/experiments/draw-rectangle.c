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
	int hight = 20, weight = 30, a = 0, b = 0;

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
			if (sscanf(ret, "\e[%d;%dR", &row, &col) == 2) {
			  printf("\nrow: %d col: %d\n", row, col);
				  break;
			}
			else {
				fprintf(stderr, "sscanf failed!\n");
				return -1;
			}
		}
		i++;
	}

	printf("\e[%d;%dH", row /= 2 , col /= 2);

		for (a = 0; a != hight; a++) {
			for (b = 0; b != weight; b++) {
			  if (a == 0 || b == 0 || a == hight-1 || b == weight-1) {
				printf("*");
			  }
			  else {
				printf(" ");
			  }
			}
		printf("\e[%d;%dH", ++row, col);
		}

	tcsetattr (STDIN_FILENO, TCSANOW, &terattr_bak);
	fflush(stdout);
	sleep(10);

	return 0;
}
