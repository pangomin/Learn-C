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
	while ((argc > 2) && (argv[2][0] == '-'))
	{
		switch (argv[2][1]) {
case 'h': printf("Hexadecimal: 0x%x\n", argv[1]); break;
		}
		break;
	}
		/*
	printf("Decimal: %d\n", x);
	printf("Octal: %o\n", x);
	printf("Hexadecimal: 0x%x\n", x);
	deci_binary(x);
	*/
	return 0;
}
