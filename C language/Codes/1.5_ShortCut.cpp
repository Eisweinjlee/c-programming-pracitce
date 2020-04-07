#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0; // always remember to initial the values
	printf("a = %d, b = %d, c = %d.\n", a, b, c);
	
	a = (b = 3, (c = b + 4) + 5); 
	// b = 3;
	// c = b + 4;
	// a = c + 5; (a is given by the equation after the last comma.)
	
	printf("a = %d, b = %d, c = %d.\n", a, b, c);
	
	return 0;
}
