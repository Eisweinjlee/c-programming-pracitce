#include <stdio.h>

int main()
{
	char str[] = "Hello pointer!";
	char *target = str;
	int count = 0;
	printf("%s\n", str);
	while (*target++ != '\0')  //while (*(str++) != '\0'), str is a readable value, cannot be changed!
	{
		count++;
	}
	printf("The size is %d.\n", count);
	printf("\n");
	
	
	// Part 2: Pointer Array
	// pointer for string is very useful!
	char* p[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	// save 7 array pointers!
	for (int i = 0; i<7;i++) // easy to print string!
	{
		printf("%s\n", p[i]);
	}
	printf("\n");
	
	// Part 3: Array pointer
	int temp[5] = {1,2,3,4,5};
	int (*pp)[5] = &temp; 
	// *pp saved the address of temp! to find the first value, use *(*pp)
	for (int i=0; i<5; i++)
	{
		printf("%-2d", *(*pp + i));
	}
	
	
	return 0;
}
