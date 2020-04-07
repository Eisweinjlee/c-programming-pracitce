#include<stdio.h>

int sum(int); // declaration (not necessary)

int sum(int n)
{
	int result = 0;
	
	do
	{
		result += n;
	}while(n-- > 0);
	
	return result;
}

int main()
{
	int n;
	printf("Input an integer N:\n");
	scanf("%d",&n);
	
	printf("The sum from 1 to %d is: %d\n", n, sum(n));
	
	return 0;
}
