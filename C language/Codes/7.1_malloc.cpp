#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr;
	ptr = (int *)malloc(sizeof(int)); // return the address to pointer ptr
	
	if(ptr == NULL)
	{
		printf("fail to call malloc.\n");
		exit(1);
	}
	
	printf("Give an integer: ");
	scanf("%d", ptr);
	
	printf("The number is: %d\n\n", *ptr);
	
	/*
	int num = 520;
	ptr = &num;
	// ptr loses the malloc address, it works but illegal.
	// when you use call(), the program comes error.
	printf("Points to &num, *ptr becomes: %d\n\n", *ptr);
	*/
	
	free(ptr); // to avoid leak
	printf("After free(), the pointer points to random value: %d", *ptr);
	
	return 0;
}
