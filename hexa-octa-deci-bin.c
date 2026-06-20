#include <stdio.h>

void deci_binary(int n) {
int binaryNum[1000];
	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

		printf("Binary: ");
	for (int j = i - 1; j>= 0; j--)
		printf("%d", binaryNum[j]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	int options;
	while (argc > 2 && argv[1][0] == '-')
		switch (options)
		/*
	printf("Decimal: %d\n", x);
	printf("Octal: %o\n", x);
	printf("Hexadecimal: 0x%x\n", x);
	deci_binary(x);
	*/
	return 0;
}
