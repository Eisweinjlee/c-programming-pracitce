#include<stdio.h>

typedef int (*PTR_TO_ARRAY)[3]; // pointer to array
typedef int (*PTR_TO_FUN)(void); // pointer to function
typedef int *(*PP_TO_FUN)(int*); // pointer of pointer to function

int aNumber(void)
{
	return 520;
}

int *funA(int* num)
{
	printf("funA(num) = %d,  ",*num);
	return num;
}
int *funB(int* num)
{
	printf("funB(num) = %d,  ",*num);
	return num;
}
int *funC(int* num)
{
	printf("funC(num) = %d,  ",*num);
	return num;
}

int main(void)
{
	// pointer to array
	int array[3] = {1,2,3};
	PTR_TO_ARRAY parray = &array;
	
	int i;
	for(i=0;i<3;i++)
	{
		printf("%d\n", (*parray)[i]);
	}
	putchar('\n');
	
	// pointer to function
	PTR_TO_FUN theFun = &aNumber;
	printf("aNumber() = %d\n\n",aNumber());
	
	// pointer of pointer to functions
	PP_TO_FUN funs[3] = {&funA,&funB,&funC};
	int* pi = &i;
	
	for(i=0;i<3;i++)
	{
		printf("addr of num: %p\n", (*funs[i])(pi));
	} 	
	return 0;
}
