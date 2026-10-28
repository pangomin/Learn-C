#include <stdio.h>

int main(void)
{
	struct ss {
		int a;
		int b;
		float c;
	};

	struct sb {
		int a;
		float c;
		char zero[4];
	};

	struct ss a;
	struct sb b;

	b = (struct sb) a;

	return 0;
}


