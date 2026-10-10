#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	const char *ANSI;
	ANSI = "\e[10A";
	write(STDOUT_FILENO, ANSI, strlen(ANSI));
}
