#include<stdio.h>
#include<stdarg.h>

int sum(int n, ...); // ... represents being not sure about the inputs

int sum(int n, ...)
{
	int i, sum =0;
	va_list vap; // a variable list initialized (a pointer)
	
	va_start(vap, n); // the first variable input
	for(i=0;i<n;i++)
	{
		sum += va_arg(vap, int);
		// va_arg(va_list NAME, DataType) .. get following variables
	}
	va_end(vap); // clear the list
	
	return sum;
}

int main()
{
	int result;
	
	result = sum(3,1,2,3);
	printf("1 + 2 + 3 = %d\n\n", result);
	result = sum(6,1,2,3,7,8,9);
	printf("1 + 2 + 3 + 7 + 8 + 9 = %d\n\n", result);
	result = sum(3,5,-2,-1);
	printf("5 - 2 - 1 = %d\n\n", result);
	
	return 0;
}
