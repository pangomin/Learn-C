#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void f(const char *ch, ...) {
	const char *str = ch;
	va_list ap;
	va_start(ap, ch);

	while(str) {
		puts(str);
		str = va_arg(ap, char*);
	}
	va_end(ap);
	return;
}
int main(void) {
	f("AA", "BB", "CC", NULL);
	return 0;
}
