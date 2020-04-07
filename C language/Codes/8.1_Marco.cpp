#include<stdio.h>

#define PI 3.14

#define MAX(x,y) (((x)>(y))?(x):(y))

int main(void)
{
	int r;
	float s;
	
	printf("The radium of circle: ");
	scanf("%d", &r);
	
	s = PI * r * r;
	printf("The square is %.2f\n", s);
	
	int a,b;
	printf("\nInput 2 integers:");
	scanf("%d %d", &a, &b);
	
	printf("The bigger one is %d", MAX(a,b));
	
	return 0;
}
