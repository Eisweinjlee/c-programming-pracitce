#include <stdio.h>

int main()
{
	// 2D array and pointer
	int array[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
	printf("sizeof int: %d\n", sizeof(int));
	printf("array at: %p\n", array);
	printf("array + 1 at: %p\n\n", array+1);
	// verify that one array is a row of 2d array
	
	// *(array + 1) => array[1] => &array[1][0]
	printf("*(array+1): %p\n", *(array+1));
	printf("array[1]: %p\n", array[1]);
	printf("&array[1][0]: %p\n", &array[1][0]);
	printf("**(array+1): %d\n\n", **(array+1));
	
	// *(array+1) + 3 => &array[1][3]
	printf("array[1][3] = %d\n",  array[1][3]);
	printf("*(*(array+1)+3) = %d\n\n", *(*(array+1)+3));	
	
	// Array pointer & 2d array
	int (*p)[5] = array;
	
	printf("**(p+1): %d\n",**(p+1));
	printf("**(array+1): %d\n", **(array+1));
	printf("array[1][0]: %d\n\n", array[1][0]);
	
	printf("*(*(p+1)+2): %d\n",*(*(p+1)+2));
	printf("*(*(array+1)+2): %d\n", *(*(array+1)+2));
	printf("array[1][2]: %d\n\n", array[1][2]);
	
	return 0;
}
