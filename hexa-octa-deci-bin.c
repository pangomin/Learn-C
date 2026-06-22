#include <stdio.h>
#include <stdlib.h>

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
	if (argc > 1) {
		printf("Decimal: %d\n", atoi(&argv[1][0]));
		printf("Hexadecimal: 0x%x\n", atoi(&argv[1][0]));
		printf("Octal: %o\n", atoi(&argv[1][0]));
		deci_binary(atoi(&argv[1][0]));
	}
	return 0;
}
