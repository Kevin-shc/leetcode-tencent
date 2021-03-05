#include <stdio.h>

int check()
{
	int t = 1;
	return *(char*)&t;     
}

int main()
{
	int i = check();
	if (1 == i)
		printf("是小端  a\n");
	else if (1 != i)
		printf("是大端  b\n");

	// system("pause");
	return 0;
}
