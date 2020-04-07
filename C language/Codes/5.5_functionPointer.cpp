#include<stdio.h>

float add(float num1, float num2)
{
	return num1+num2;
}
float min(float num1, float num2)
{
	return num1-num2;
}
float mul(float num1, float num2)
{
	return num1*num2;
}
float sub(float num1, float num2)
{
	return num1/num2;
}
// the function can accept the function pointer (*fp)
float calc(float (*fp)(float, float), float num1, float num2)
{
	return (*fp)(num1,num2);
}

// the function can return a function pointer
float (*select(char op))(float, float) // all of those return fun have 2 augments!
{
	switch(op)
	{
		case '+': return add;
		case '-': return min;
		case '*': return mul;
		case '/': return sub;
	}
}

int main()
{
	float num1, num2;
	char op;
	float (*fp)(float, float);
	
	printf("Input a simple calculation (float1)(+,-,*,/)(float2):\n");
	scanf("%f %c %f", &num1, &op, &num2);
	
	fp = select(op);
	
	printf("\nfp(operation): %p\n\n", fp);
	printf("+: %p\n-: %p\n*: %p\n/: %p\n\n", add, min, mul, sub);
	
	printf("Result:\n%.2f %c %.2f = %.2f\n", num1, op, num2, calc(fp, num1, num2));
	
	return 0;
}
