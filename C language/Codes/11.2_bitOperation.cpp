#include<stdio.h>

int main(void)
{
	int value = 1;
	while(value < 1024)
	{
		printf("value = %d\n", value);
		value <<= 1; // value = value << 1;
	}
	
	printf("\n");
	
	return 0;
}
