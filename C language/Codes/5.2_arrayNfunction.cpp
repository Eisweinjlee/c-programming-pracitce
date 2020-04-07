#include <stdio.h>

void get_array(int array[10]);

void get_array(int array[10])
{
	int i;
	printf("In function, the sizeof array: %d <-- the size of an address.\n\n", sizeof(array));
	array[5] = 0; // this would change the main function
	// so the array input is an address
	
	for(i=0; i<10; i++)
	{
		printf("%-2d", array[i]);
	}
	printf("\n");
}

int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("In main(), the sizeof a: %d <-- the size of 10-integer array\n", sizeof(a));
	get_array(a); // so here, a is actually a head address of a[]
	
	for(int i=0; i<10; i++)
	{
		printf("%-2d", a[i]); // the change of a[5] is shown!
	}
	
	return 0;
}
