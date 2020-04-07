#include <stdio.h>
// how to initialize the array

int main()
{
	int a[10] = {};
	int b[10] = {0};
	int c[10] = {1};
	int d[10] = {1,2,3};
	//int e[10] = {[3]=5, [5]=8, [8]=10};
	int i;
	
	printf("a[10] = ");
	for (i=0;i<10;i++) printf("%-2d", a[i]);
	printf("\n");
	
	printf("b[10] = ");
	for (i=0;i<10;i++) printf("%-2d", b[i]);
	printf("\n");
	
	printf("c[10] = ");
	for (i=0;i<10;i++) printf("%-2d", c[i]);
	printf("\n");
	
	printf("d[10] = ");
	for (i=0;i<10;i++) printf("%-2d", d[i]);
	printf("\n");
	
	//printf("e[10] = ");
	//for (i=0;i<10;i++) printf("%-2d", e[i]);
	//printf("\n");
	
	return 0;
}
