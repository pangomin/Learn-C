#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void my_printf(const char *c, ...) {
	char buf[BUFSIZ];
	char *str;
	int value;
	va_list ap;
	va_start(ap, c);

	while(*c != '\0') {
		if(*c == '%') {
			c++;
			switch(*c)
			{
case 'd':
	{
		value = va_arg(ap, int);
		sprintf(buf, "%d", value);
		my_printf(buf);
		c++;
		break;
	}
case 's':
	{
		str = va_arg(ap, char*);
		my_printf(str);
		c++;
		break;
	}
default:
	{
		my_printf("\nWrong format specifier!\n");
		va_end(ap);
		return;
	}
			}
		}
		else if(*c != '%' && *c != '\0') {
			write(1, c, 1);
			c++;
			continue;
		}
		if(*c == '\0') {
			break;
		}
	}
	return;
}

int main(void) {
	int x = 4;
	int y = 6;
	char *str = "string srting srting";
	my_printf("something\n");
	my_printf("x is %d\ny is %d\n", x, y);
	my_printf("a string: %s\nagain, x is %d\n", str, x);
	return 0;
}
