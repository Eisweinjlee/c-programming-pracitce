#include<stdio.h>
#include<string.h>

union Test
{
	int i;
	double pi;
	char str[15];
};

int main(void)
{
	union Test test;
	
	test.i = 520;
	test.pi = 3.1415;
	strcpy(test.str, "What is union?");
	
	// common address
	printf("test.i   is at %p\n", &test.i);
	printf("test.pi  is at %p\n", &test.pi);
	printf("test.str is at %p\n", &test.str);
	
	// print the value
	printf("test.i: %d\n",test.i); // overwritten
	printf("test.pi: %f\n",test.pi); // overwritten
	printf("test.str: %s\n",test.str); // only the last one is correct
	
	printf("\nThe size of this union: %d\n", sizeof(test));
	
	return 0;
}
