#include<stdio.h>

int a, b = 520; // a would be 0 by default.

void func()
{
	int b; // once a function define "b", the global one would be ignored
	
	a = 880; // but the "a" is still used as global one!!
	b = 120;
	
	printf("In func, a = %d, b = %d\n", a, b);
}

int main()
{
	printf("In main, a = %d, b = %d\n", a, b);
	func();
	printf("In main, after func(), a = %d, b = %d\n", a, b);

	return 0;
}


