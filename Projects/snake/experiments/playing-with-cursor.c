#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>


int main(void)
{
	struct termios terattr, terattr_bak;
	tcgetattr(STDIN_FILENO, &terattr);
	terattr_bak = terattr;
	terattr.c_lflag |= ECHO;
	terattr.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &terattr);
	char ret[100];
	int row, col, i = 0;

	printf("\e[s");					// save cursor position
	printf("\e[999999;999999H");	    	// set row and col
	printf("\e[6n");				// req cursor pos
	fflush(stdout);
	while (i < 100) {
		if (read(STDIN_FILENO, &ret[i], 1) == 0) {
			break;
		}
		if (ret[i] == 'R') {
			ret[i+1] = '\0';
			if (sscanf(ret, "\e[%d;%d", &row, &col) == 2) {
				fprintf(stderr, "row: %d col: %d\n", row, col);
			}
			break;
		}
		else {
			i++;
		}
	}

	tcsetattr (STDIN_FILENO, TCSANOW, &terattr_bak);
	fflush(stdout);
	row /= 2;
	col /= 2;
		printf("\e[%d;%dH\e[2J", row, col);	    	// set row and col
													//
		fflush(stdout);
	printf("\e[s");					// save cursor position
		fflush(stdout);
		i = 0;
		while(i < row) {
			fputs("*\n", stdout);
			fflush(stdout);
			i++;

		fflush(stdout);
		}
		printf("\e[u");

		fflush(stdout);
		i = 0;
		while(i < col) {
			fputs("*", stdout);
			fflush(stdout);
			i++;
		}

		printf("\e[u");
		fflush(stdout);
	return 0;
}
