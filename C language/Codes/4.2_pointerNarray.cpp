#include <stdio.h>
#include <string.h>

// pointer and array (string is a char array)
int main()
{
	// part 1
	char str[128] = "Good day, my friend!";
	printf("Input a sentence: %s\n",str);
	printf("str address is : %p\n", str);
	printf("str address is : %p\n", &str[0]);
	printf("\n");
	
	// part 2
	printf("See how many addresses they take.\n");
	
	char a[] = "Wow! Pointer!";
	int b[] = {1,2,3,4,5};
	float c[] = {1.1,2.2,3.3,4.4,5.5};
	
	printf("char a(1B): %p -> %p -> %p\n", &a[0], &a[1], &a[2]);
	printf("int b(4B): %p -> %p -> %p\n", &b[0], &b[1], &b[2]);
	printf("float c(4B): %p -> %p -> %p\n", &c[0], &c[1], &c[2]);
	printf("\n");
	
	// part 3
	printf("Make a pointer for array\n");
	int* p = b; // also: char* p = &str[0];
	printf("*p = %d, *(p+1) = %d, *(p+2) = %d, ...\n", *p, *(p+1), *(p+2));
	printf("*b = %d, *(b+1) = %d, *(b+2) = %d, ...\n", *b, *(b+1), *(b+2));
	printf("\n");
	// the pointer is moved with 1 element not 1 byte!!
	// also the name of array is also a pointer!!
	
	//part 4
	char* arr = "Now you know the array name can be a pointer!"; // char* arr <=> char arr[] ?
	int i, length;
	length = strlen(arr);
	for(i=0;i<length;i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
	
	
	return 0;
}
