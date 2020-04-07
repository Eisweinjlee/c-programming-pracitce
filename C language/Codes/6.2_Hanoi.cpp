#include<stdio.h>

void hanoi(int n, char x, char y, char z)
{
	
	if(n==1) // termination
	{
		printf("%c -> %c\n", x, z);
		// the last step is move the last layer from X to Z
	}
	else
	{
		hanoi(n-1, x, z, y); // move n-1 layers from X to Y
		printf("%c -> %c\n", x, z); // the n-th layer from X to Z
		hanoi(n-1, y, x, z); // move n-1 layers from Y to Z
	}
}

int main(void)
{
	int n;
	
	printf("The layer of Hanoi: ");
	scanf("%d", &n);
	
	hanoi(n, 'X', 'Y', 'Z');
	
	return 0;
}
