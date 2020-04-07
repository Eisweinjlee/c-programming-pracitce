#include<stdio.h>

void recursion_Hi(void)
{
	static int count = 10;
	printf("Hi! ");
	
	if (--count)
	{
		recursion_Hi();	
	}
}

long factorial(int num)
{
	long result;
	if (num > 0)
	{
		result = num * factorial(num - 1);
	}
	else
	{
		result = 1;
	}
	return result;
}

int main()
{
	int num;
	printf("Give a number for factorial: ");
	scanf("%d", &num);
	
	//recursion_Hi();
	
	printf("%d! = %ld\n", num, factorial(num));
	
	return 0;
}
