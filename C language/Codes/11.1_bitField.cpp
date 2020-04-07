#include<stdio.h>

int main(void)
{
	struct Test
	{
		unsigned int a:4;
		unsigned int b:4;
		unsigned int c:8;
		unsigned int  :16;
	};
	
	struct Test test;
	test.a = 0;
	test.b = 1;
	test.c = 2;
	
	printf("a = %d, b = %d, c = %d\n", test.a, test.b, test.c);
	printf("sizeof(test): %d\n", sizeof(test));
	
	return 0;
}
