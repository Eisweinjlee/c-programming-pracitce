#include<stdio.h>

int count = 0; // global variable(default = 0)

void a()
{
	// extern count;
	count++;
}

// int count = 0; // illegal, because a() cannot use count!
// but we can add "extern count;" in a().

void b()
{
	count++;
}

void c()
{
	count++;
}

int main()
{
	a();
	b();
	c();
	b();
	
	printf("count = %d\n", count);
	
	return 0;
}
