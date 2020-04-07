#include <stdio.h>
// Is it prime number?

int main()
{
	long i, num, factor;
	bool flag =1;
	
	printf("Input an integer:\n");
	scanf("%ld",&num);
	
	for(i=2;i < num/2; i++)
	{
		if (num%i == 0)
		{
			factor = i;
			flag = 0;
			break; // do not forget
		}
	}
	
	if (flag == 0)
	{
		printf("\nNot prime number, the smallest factor is %ld.\n", factor);
	}
	else
	{
		printf("\nPrime number!\n");
	}
	
	return 0;
}
