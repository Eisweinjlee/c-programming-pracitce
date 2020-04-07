#include <stdio.h>

int main()
{
	int a = 1234;
	int *pa = &a;
	
	char b = 'F';
	char *pb = &b;
	
	printf("the point of value a is *pa, and we can see:\n");
	printf("a = %d\n", a);
	printf("&a = %d = %p\n", &a,&a);
	printf("*pa = %d\n", *pa);
	printf("pa = %d  = %p\n", pa,pa);
	printf("sizeof pa is %d (64bit), and sizeof *pa is %d.\n", sizeof(pa), sizeof(*pa));
	printf("\n");
	
	printf("the point of char b is *pb, and we can see:\n");
	printf("b = %c\n", b);
	printf("&b = %d = %p\n", &b,&b);
	printf("*pb = %c\n", *pb);
	printf("pb = %d = %p\n", pb,pb);
	printf("sizeof pb is %d (64bit), and sizeof *pb is %d.\n", sizeof(pb), sizeof(*pb));
	printf("\n");
	
	printf("We can operate the value with pointer!\n\n");
	printf("*pa + 100 = %d\n", *pa + 100);
	printf("*pb + 3 = %c\n", *pb + 3);
	printf("\n");
	
	
	printf("Can we change the address to search value? Yes, but not different data type!!\n\n");
	printf("pb + 1 = %d  = %p\n", pb + 1,pb + 1); // the pb is defined as char pointer, os 1 poistion moves 1 byte!
	printf("*(pb+1) = %d \n", *(pb+1)); // it cannot print the 4-byte int, because it only read 1-byte.
	printf("\n");
	
	printf("pa - 1 = %d = %p\n",pa - 1,pa - 1); // the pa is defined as int pointer, so 1 position moves 4 byte!
	printf("*(pa-1) = %c \n", *(pa+1)); // it cannot print anything, because it cannot find a int!
	
	return 0;
}
