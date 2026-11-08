#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	size_t i;
	for (i = 0; i < len; i++)
		printf("%.2X", start[i]);
	putc('\n', stdout);

	return;
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((void*) &x, sizeof(void *));
}

int main(void) {
	byte_pointer byte = "96";
	byte_pointer *p = &byte;

	show_bytes(byte, sizeof(byte_pointer));
	show_int(100);
	show_float(100.0);
	show_pointer(p);
}
