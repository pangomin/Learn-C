#include <stdio.h>
#include <stdarg.h>

void simple_printf(const char *fmt, ...)
{
	char buf[100];
	char *str;
	int value;
	va_list ap;
	va_start(ap, fmt);

	while(*fmt != '\0') {
		if(*fmt == '%') {
			fmt++;
			switch(*fmt)
			{
case 'd':
	{
			value = va_arg(ap, int);
			sprintf(buf, "%d", value);
			simple_printf(buf);
			fmt++;
			break;
	}
case 's':
	{
			  str = va_arg(ap, char*);
			  simple_printf(str);
			  fmt++;
			  break;
	}
default:
	{
			simple_printf("\nWrong format specifier!\n");
			va_end(ap);
			return;
	}
			}
		} else {
		putc(*fmt, stdout);
		fmt++;
		continue;
	}
	va_end(ap);
}
}

int main(void) {
	simple_printf("%dss%s%w", 10, "ABC");
	return 0;
}
