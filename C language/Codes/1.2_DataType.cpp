#include <stdio.h>
#include <math.h>

int main(){
	printf("The size of int is %d\n", sizeof(int));
	printf("Short int is %d\n", sizeof(short));
	printf("Long int is %d\n", sizeof(long));
	printf("Float is %d\n", sizeof(float));
	printf("Double is %d\n", sizeof(double));
	printf("Long double is %d\n\n", sizeof(long double));
	
	printf("unsigned int is %d\n", sizeof(unsigned int));
	printf("signed int is %d\n\n", sizeof(signed int));
	
	unsigned int a;
	signed int b;
	
	a = pow(2,32)-1;
	b = pow(2,32)-1; // overflow warning should be there.
	
	printf("Maximum of unsigned int is %u, of signed int is %d\n", a, b);
	printf("Signed integers need the first digit to specify the sign of value.");
	
	return 0;	
}
