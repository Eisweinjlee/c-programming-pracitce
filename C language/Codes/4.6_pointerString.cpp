#include <stdio.h>

int main()
{
	int num = 520;
	int* p = &num;
	int** pp = &p;
	printf("num: %d, *p = %d, **pp = %d\n\n", num, *p, **pp);
	printf("p: %p, *pp: %p\n\n", p, *pp);
	printf("pp: %p\n\n", pp);
	
	
	//Part 2: The Pointer array and Pointer to string
	char* str[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	// remember that string names are pointer!
	char** Happy[3] = {};
	char** NoSchool[2] = {};
	
	NoSchool[0] = &str[5];
	NoSchool[1] = &str[6];
	
	Happy[0] = &str[4];
	Happy[1] = NoSchool[0];
	Happy[2] = NoSchool[1];
	
	printf("Happy days are:\n");
	for(int i=0; i<3; i++)
	{
		printf("%s\n", *Happy[i]);
	}
	printf("\nNo-school days are:\n");
	for(int i=0; i<2; i++)
	{
		printf("%s\n", *NoSchool[i]);
	}
	
	
	// Part 3: Array pointer
	printf("\n");
	int array[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}}; //array[][4] also works, remember?
	//int* p_array = array; // this cannot work, because p_array + 1 moves 4B(int), but array + 1 moves 4x4B(2d array)
	int (*p_array)[4] = array;
	
	printf("array[3][4] = \n");
	for(int i=0; i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%2d ", *(*(p_array+i)+j));
		}
		printf("\n");
	}

	
	return 0;
}
